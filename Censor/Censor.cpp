#include <iostream>
#pragma warning(disable:4996)

bool islower(char a)
{
    return a >= 'a' && a <= 'z';
}

class Censor
{
    //bool forbidden[26]{ false };

    bool (*shoulCensor)(char ch);

    void printLetter(char a)const
    {
        
        //if (islower(a) && forbidden[a - 'a'])
        if(shoulCensor(a))
        {
            std::cout << '*';
        }
        else std::cout << a;
    }
public:
    Censor() :shoulCensor([](char ch) {return false; }){}
    Censor(bool (*pred)(char ch)):shoulCensor(pred){}

    //void addLetter(char a)
    //{
    //    if (!islower(a))
    //        return;
    //   // forbidden[a - 'a'] = true;
    //}

    void print(const char* str)const
    {
        if (!str)return;
        while (*str)
        {
            printLetter(*str);
            str++;
        }
        std::cout << std::endl;
    }

};

constexpr int BUFF_SIZE = 20;
class Text
{
    char buff[BUFF_SIZE + 1] = "";
    Censor& censor;
    void setBuffer(const char* val)
    {
        if (strlen(val) > BUFF_SIZE) { return; }
           
        strcpy(buff, val);
    }

public:
    Text(Censor& c, const char* buff) :censor(c)
    {
        setBuffer(buff);
    }
    void print()const
    {
        censor.print(buff);
    }

};



int main()
{
    Censor c1([](char ch) {return ch >= '0' && ch <= '9'; });
    //c1.addLetter('e');
    Text t1(c1, "hel3232lo");
    Text t2(c1, "1111eeeeee");

    t1.print();
    t2.print();
}
