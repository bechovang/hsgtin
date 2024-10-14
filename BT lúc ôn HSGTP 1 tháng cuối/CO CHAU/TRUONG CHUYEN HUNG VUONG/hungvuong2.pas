program count2;
const
     fi = 'COUNT10.INP';
     fo = 'COUNT10.OUT';
Var
    stack, count: array [1..500000] of longint;
    n,top: longint;
    res: int64;
Procedure solve;
Var  i,k: longint;
begin
     readln(n);
     readln(n);
     stack[1] := k;
     count[1]:= 1;
     res := 0;
     top := 1;
     for i:= 2 to n do
     begin
          readln(k);
          while(top>0) and (stack[top] <k) do
          begin
               res := res + count[top];
               dec(top);
          end;
          if top =0  then
            begin
               top := 1;
               stack[top] := k;
               count[top] := 1;
            end
          else
            begin
                 if stack[top] = k then
                 begin
                      res := res + count[top];
                      inc(count[top]);
                      if top <> 1 then inc(res);
                 end
                 else
                    if stack[top] > k then
                     begin
                          inc(res);
                          inc(top);
                          stack[top] := k;
                          count[top] := 1;
                     end;
            end;
     end;
end;

begin
     assign(input,fi); reset(input);
     assign(output,fo); rewrite(output);
     solve;
     writeln(res);
     close(input);
     close(output);
end.