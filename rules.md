Задание
1. Написать парсер методом рекурсивного спуска.
```
<PROG>->PROG id<VAR> begin<LISTST> end
<VAR>->VAR<IDLIST> : <TYPE>
<IDLIST>->id<A>
<A>->E |, id<A>
<LISTST>-> <ST> | <B>
<B> -> E| <ST> <B>
<TYPE>->int	| float | bool | string
<ST>-><READ> | <WRITE> | <ASSIGN>
<ASSIGN>->id : = <EXP>;
<EXP>-><EXP> + <T> | <T>
<T>-><T>*<F> | <F>
<F>->- <F> | (<EXP>) | id | num
<READ>->READ(<IDLIST>);
<WRITE>->WRITE(<IDLIST>);
```

2. Добавить диагностику ошибок.
3. Проверить на «чистых» и «грязных» тестах.

Проверочный тест
```
PROG id;
VAR id, id, id : int;
BEGIN
READ(id, id);
Id : = id + num * -(-num + id * id * -num * (id + -num));
WRITE(id, id, id);
END
```