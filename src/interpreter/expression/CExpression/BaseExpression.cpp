#include "pch.h"

#include "BaseExpression.h"

namespace interpreter::expression
{

IExpressionSharedPtr BaseExpression::Copy() const
{
	return IExpressionSharedPtr();
}

void BaseExpression::Evaluate(Context& context)
{
}

IExpressionSharedPtr BaseExpression::Replace(const std::string& name, const IExpressionSharedPtr& exp) const
{
	return IExpressionSharedPtr();
}


} // namespace interpreter::expression
