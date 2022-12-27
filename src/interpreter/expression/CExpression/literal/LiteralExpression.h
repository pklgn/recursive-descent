#pragma once

#include "../BaseExpression.h"

namespace interpreter::expression
{

class LiteralExpression : public BaseExpression
{
public:
	using MyBase = BaseExpression;

	explicit LiteralExpression() = default;

	void Evaluate(Context& context) override;

private:
};

} // namespace interpreter::expression
