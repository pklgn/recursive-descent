#pragma once

#include "../IExpression.h"

namespace interpreter::expression
{

class BaseExpression : public IExpression
{
public:
	explicit BaseExpression() = default;

	IExpressionSharedPtr Copy() const override;
	void Evaluate(Context& context) override;
	IExpressionSharedPtr Replace(const std::string& name, const IExpressionSharedPtr& exp) const override;

protected:
	explicit BaseExpression() = default;

private:
};

} // namespace interpreter::expression
