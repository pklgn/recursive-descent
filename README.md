
# Рекурсинвый спуск

1. Написать парсер методом рекурсивного спуска.

```
<PROG>   -> PROG id<VAR> begin<LISTST> end
<VAR>    -> VAR<IDLIST>: <TYPE>;
<IDLIST> -> id<A>
<A>      -> E | , id<A>
<LISTST> -> <ST><B>
<B>      -> E | <ST> <B> // <B> == <LISTST_RIGHT>
<TYPE>   -> int	| float | bool | string
<ST>     -> <READ> | <WRITE> | <ASSIGN>
<ASSIGN> -> id := <EXP>;
<EXP> -> <T><C> // <C> == <EXP_RIGHT>
<C> -> E | + <T><C>
<T> -> <F><D>
<D> -> E| * <F> <D> // <D> == <T_RIGHT>
<F>      -> -<F> | (<EXP>) | id | num
<READ>   -> READ(<IDLIST>);
<WRITE>  -> WRITE(<IDLIST>);
```

*Игнорируем пробелы*

2. Добавить диагностику ошибок.

3. Проверить на **чистых** и **грязных** тестах.

Проверочный тест

```
PROG id 
    VAR id, id, id: int;
BEGIN
    READ(id, id);
    Id := id + num * -(-num + id * id * -num * (id + -num));
    WRITE(id, id, id);
END
```

![LifeTime диаграмма](https://lh4.googleusercontent.com/XN4k217ad4BHo25yIuq00NQNBSC9H6wxWqXmQpMJS4ehYcdBf0sN8ThixR0ouJL8bmA=w2400)