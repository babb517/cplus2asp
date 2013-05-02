:- begin_lua.

function a()
return 7
end

:- end_lua.


:- constants
	p(computed)	:: sdFluent;
	q :: sdFluent.

caused p(@a()).

caused q if @a() = 7.

