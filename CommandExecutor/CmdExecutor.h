#pragma once
#include "VectorCommand.h"
#include "MyQueue.hpp"
#include "MyStack.hpp"
#include "Polymorphic_Ptr.hpp"
#include "SwapCommand.h"
#include "SortCommand.h"

class CmdExecutor
{
	MyQueue<Polymorphic_Ptr<VectorCommand>> toBeExecuted;
	MyStack<Polymorphic_Ptr<VectorCommand>, 64> history;

	CmdExecutor() = default;
	~CmdExecutor() = default;

public:
	void add(VectorCommand* c);
	void execute();
	void executeAll();
	void undo();
	static CmdExecutor& getInstance()
	{
		static CmdExecutor executor;
		return executor;
	}

	CmdExecutor(const CmdExecutor&) = delete;
	CmdExecutor& operator=(const CmdExecutor&) = delete;
};

