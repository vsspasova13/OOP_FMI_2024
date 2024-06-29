#include <iostream>
#include "../StringView/StringView.h"
#include "../MyString/MyString.h"
#include <assert.h>

constexpr unsigned LETTERS_COUNT = 26;

class BooleanInterpretation
{
private:
    bool values[LETTERS_COUNT]{ false };

public:
    void set(char ch, bool value)
    {
        assert(ch >= 'a' && ch <= 'z');
        values[ch - 'a'] = value;
    }

    bool operator()(char ch)const
    {
        assert(ch >= 'a' && ch <= 'z');
        return values[ch - 'a'];
    }

    size_t getTrueCount()const
    {
        size_t count = 0;
        for (size_t i = 0; i < LETTERS_COUNT; i++)
        {
            if (values[i])
                count++;
        }
        return count;
    }
    void excludeValuesByMask(unsigned mask)
    {
        int lett = LETTERS_COUNT - 1;
        for (int i = lett; i >=0; i--)
        {
            if (values[i])
            {
                if (mask % 2 == 0)
                    values[i] = false;
                mask /= 2;
            }
        }
    }
};

struct BooleanExpression
{
    BooleanExpression() = default;
    BooleanExpression(const BooleanExpression& other) = delete;
    BooleanExpression& operator=(const BooleanExpression& other) = delete;

    virtual bool eval(const BooleanInterpretation& interpret)const = 0;
    virtual ~BooleanExpression() = default;
    virtual BooleanExpression* clone()const = 0;

    virtual void populateVariables(BooleanInterpretation& interpret)const = 0;
};

struct Var :BooleanExpression
{
private:
    char ch;

public:
    Var(char ch) :ch(ch) {};
    bool eval(const BooleanInterpretation& interpret)const override
    {
        return interpret(ch);
    }
    BooleanExpression* clone()const override
    {
        return new Var(ch);
    }
    void populateVariables(BooleanInterpretation& interpret)const override
    {
        interpret.set(ch, true);
    }
};

struct UnaryOperation :BooleanExpression
{
protected:
    BooleanExpression* expr;

public:
    UnaryOperation(BooleanExpression* expr) :expr(expr) {};
    void populateVariables(BooleanInterpretation& interpret)const override
    {
        expr->populateVariables(interpret);
    }
    ~UnaryOperation()
    {
        delete expr;
    }
};

struct Negation :UnaryOperation
{
    Negation(BooleanExpression* expr) :UnaryOperation(expr) {};
    virtual BooleanExpression* clone()const override
    {
        return new Negation(expr->clone());
    }
    bool eval(const BooleanInterpretation& interpret)const override
    {
        return !expr->eval(interpret);
    }

};

struct BinaryOperation : BooleanExpression
{
protected:
    BooleanExpression* lhs;
    BooleanExpression* rhs;

public:
    BinaryOperation(BooleanExpression* lhs, BooleanExpression* rhs) :lhs(lhs), rhs(rhs) {};
    void populateVariables(BooleanInterpretation& interpret)const override
    {
        lhs->populateVariables(interpret);
        rhs->populateVariables(interpret);
    }
    ~BinaryOperation()
    {
        delete lhs;
        delete rhs;
    }
};

struct Conjunction :BinaryOperation
{
    Conjunction(BooleanExpression* lhs, BooleanExpression* rhs) :BinaryOperation(lhs, rhs) {};
    bool eval(const BooleanInterpretation& interpret)const override
    {
        return lhs->eval(interpret) && rhs->eval(interpret);
    }
    BooleanExpression* clone()const override
    {
        return new Conjunction(lhs->clone(), rhs->clone());
    }
        
};


struct Disjunction :BinaryOperation
{
    Disjunction(BooleanExpression* lhs, BooleanExpression* rhs) :BinaryOperation(lhs, rhs) {};
    BooleanExpression* clone()const override
    {
        return new Disjunction(lhs->clone(), rhs->clone());
    }
    bool eval(const BooleanInterpretation& interpret)const override
    {
        return lhs->eval(interpret) || rhs->eval(interpret);
    }

};

struct Implies : BinaryOperation
{
    Implies(BooleanExpression* left, BooleanExpression* right) : BinaryOperation(left, right) {}

    BooleanExpression* clone() const override
    {
        return new Implies(lhs->clone(), rhs->clone());
    }

    bool eval(const BooleanInterpretation& interpret)const override
    {
        return !lhs->eval(interpret) || rhs->eval(interpret);
    }
};

BooleanExpression* expressionFactory(StringView str)
{
    str = str.substr(1, str.length() - 2);

    if (str.length() == 1)
        return new Var(str[0]);
    unsigned count = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
            count--;
        else if (count == 0)
        {
            switch (str[i])
            {
            case '!':return new Negation(expressionFactory(str.substr(i + 1, str.length() - 1 - i)));
            case '&':return new Conjunction(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i + 1, str.length() - i - 1)));
            case '|':return new Disjunction(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i + 1, str.length() - i - 1)));
            case '>': return new Implies(expressionFactory(str.substr(0, i)), expressionFactory(str.substr(i + 1, str.length() - i - 1)));
            }

        }

    }
    throw std::invalid_argument("Invalid expression!");

}

class BooleanHandler
{
private:
    BooleanInterpretation myVariables;
    BooleanExpression* expr = nullptr;

    void free()
    {
        delete expr;
    }
    void copyFrom(const BooleanHandler& other)
    {
        expr = other.expr->clone();
    }
    void moveFrom(BooleanHandler&& other)
    {
        expr = other.expr;
        other.expr = nullptr;
    }
    bool checkAllTruthAssigments(bool value)const
    {
        size_t varsCount = myVariables.getTrueCount();
        size_t powerOfTwo = 1 << varsCount;
        for (size_t i = 0; i < powerOfTwo; i++)
        {
            BooleanInterpretation curr = myVariables;
            curr.excludeValuesByMask(i);
            if (expr->eval(curr) != value)
                return false;
        }
    }
public:
    BooleanHandler(const MyString& str)
    {
        expr = expressionFactory(str);
    }
    BooleanHandler(const BooleanHandler& other)
    {
        copyFrom(other);
    }
    BooleanHandler& operator=(const BooleanHandler& other)
    {
        if (this != &other)
        {
            free();
            copyFrom(other);
        }
        return *this;
    }

    BooleanHandler(BooleanHandler&& other) noexcept
    {
        moveFrom(std::move(other));
    }
    BooleanHandler& operator=(BooleanHandler&& other) noexcept
    {
        if (this != &other)
        {
            free();
            moveFrom(std::move(other));
        }
        return *this;
    }

    ~BooleanHandler()
    {
        free();
    }

    bool evaluate(const BooleanInterpretation& bi)const
    {
        return expr->eval(bi);
    }

    bool isTautology()const
    {
        return checkAllTruthAssigments(true);
    }
    bool isContradiction()const
    {
        return checkAllTruthAssigments(false);
    }
};

int main()
{
    BooleanHandler be("((p)|((q)&(t)))");
    BooleanInterpretation bi;
    bi.set('p', true);
    std::cout << be.evaluate(bi) << std::endl;
    BooleanHandler be2("((p)|(!(p)))");
    std::cout << be2.isTautology() << std::endl;
}
