-module(teststringadd).
-include_lib("eunit/include/eunit.hrl").
-import(stringadd, [add/2]).
-export([test_all/0, test_perform/0, run_perform/1]).

test_single_num() -> 
	?assert(add("1", "2") == "3").

test_single_carrybit() -> 
	?assert(add("3", "9") == "12").

test_multi_num() -> 
	?assert(add("33", "23") == "56").

test_multi_num_carrybit() -> 
	?assert(add("999", "22") == "1021").

test_multi_bignumber() -> 
	?assert(add("123456789123456789123456789123456789123456789", "222") == "123456789123456789123456789123456789123457011").

run_perform(0) -> 0;
run_perform(N) -> 
	test_multi_bignumber(),
	run_perform(N-1).

test_perform() ->
	Times = 10000,
	{MilliSecond, _} = timer:tc(?MODULE, run_perform, [Times]), % 累计计算Times次数大数值加法
	io:format("Costs ~p milliseconds!~n", [MilliSecond div 1000]).
	
test_all() ->
	test_single_num(),
	test_single_carrybit(),
	test_multi_num(),
	test_multi_num_carrybit(),
	test_multi_bignumber(),
	test_perform().
