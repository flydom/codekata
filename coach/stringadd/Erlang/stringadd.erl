-module(stringadd).
-export([add/2, stringadd/2]).

getnum([])    -> 0;      % 获取整数中的其中一位
getnum([H|_]) -> H - $0.

next([])    -> [];
next([_|T]) -> T.

addnum([], [], CarryBit, Result) -> 
	case CarryBit > 0 of
		true  -> lists:append(integer_to_list(CarryBit), Result);  % 当最高位有进位时，把进位值加上
		false -> Result
	end;
addnum(Left, Right, LastCarryBit, Result) ->
	Sum = getnum(Left) + getnum(Right) + LastCarryBit,
	CarryBit  = Sum div 10,
	Remainder = Sum rem 10,
	addnum(next(Left), next(Right), CarryBit, lists:append(integer_to_list(Remainder), Result)).
	
add(X, Y) -> addnum(lists:reverse(X), lists:reverse(Y), 0, "").	

stringadd(X, Y) -> integer_to_list(list_to_integer(X) + list_to_integer(Y)).