uses crt;

var n, i, maxn, maxp, temp:integer;

begin
	readln(n);
	maxn := 0; maxp := 0;
	for i := 1 to n do
		begin
			read(temp);
			if temp >= maxn then
				begin
					maxn := temp;
					maxp := i;
				end;
		end;
	write(maxn); write(' '); write(maxp);
end.