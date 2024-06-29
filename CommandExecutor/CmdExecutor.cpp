#include "CmdExecutor.h"

void CmdExecutor::add(VectorCommand* c)
{
	toBeExecuted.push(c);
}

void CmdExecutor::execute()
{
	if (!toBeExecuted.isEmpty())
	{
		Polymorphic_Ptr<VectorCommand> temp = toBeExecuted.peek();
		temp->execute();
		toBeExecuted.pop();
		history.push(temp);
	}
}

void CmdExecutor::executeAll()
{
	while(!toBeExecuted.isEmpty())
	{
		execute();
	}
}

void CmdExecutor::undo()
{
	if (!history.isEmpty())
	{
		Polymorphic_Ptr<VectorCommand> temp = history.peek();
		temp->undo();

		history.pop();
	}
}
