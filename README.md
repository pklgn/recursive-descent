
# Рекурсивный спуск

1. Написать парсер методом рекурсивного спуска.

```
<PROG> -> PROG id <VAR> begin <LISTST> end
<VAR> -> VAR <IDLIST> : <TYPE>
<IDLIST> -> id | <IDLIST>, id
<LISTST> -> <ST> | <LISTST><ST>
<TYPE> -> int|float|bool|string
<ST> -> <READ>|<WRITE>|<ASSIGN>
<ASSIGN> -> id := < EXP>;
<EXP> ->  <EXP> + <T> | <T>
<T> -> <T>*<F> | <F>
<F> -> -<F>|(<EXP>)| id | num
<READ> -> READ (<IDLIST>);
<WRITE> -> WRITE (<IDLIST>);
```

Преобразованные правила без левой рекурсии:
```
<PROG>         -> PROG id <VAR> begin <LISTST> end
<VAR>          -> VAR <IDLIST> : <TYPE>;
<IDLIST>       -> id<IDLIST_RIGHT>
<IDLIST_RIGHT> -> E | , id<IDLIST_RIGHT>
<LISTST>       -> <ST><LISTST_RIGHT>
<LISTST_RIGHT> -> E | <ST> <LISTST_RIGHT>
<TYPE>         -> int | float | bool | string
<ST>           -> <READ> | <WRITE> | <ASSIGN>
<ASSIGN>       -> id := <EXP>;
<EXP>          -> <T><EXP_RIGHT>
<EXP_RIGHT>    -> E | + <T><EXP_RIGHT>
<T>            -> <F><T_RIGHT>
<T_RIGHT>      -> E | * <F><T_RIGHT>
<F>            -> -<F> | (<EXP>) | id | num
<READ>         -> READ(<IDLIST>);
<WRITE>        -> WRITE(<IDLIST>);
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