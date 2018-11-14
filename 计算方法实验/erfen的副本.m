function x = erfen(f,a,b,e)
% f是函数名 a,b是区间端点，e为精度
fa = feval(f,a); % feval是求函数值
fb = feval(f,b);
if fa*fb>0
    error('此函数在[%d,%d]区间无解',a,b);
end

k = 0;
x = (a+b)/2;
while(b-a)>(2*e)
    fx=feval(f,x);
    if fa*fx<0
        b=x;
        fb=fx;
    else
        a=x;
        fb=fx;
    end
    k=k+1;
    x=(a+b)/2;
    
    fprintf("%d:x=%f\n", k, x);
    
end

