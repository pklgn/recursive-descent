#pragma once

#include "../BaseExpression.h"

namespace interpreter::expression
{

class WriteExpression : public BaseExpression
{
public:
	using MyBaase = BaseExpression;

	explicit WriteExpression() = default;

	void Evaluate(Context& context) override;

private:
};

} // namespace interpreter::expression
