function x = newton(f,fd,x0,e)
% f->f(x)
% fd->f'(x)
% x0=0
% e=0.0005

N = 100; %最大迭代次数100
x = x0;
x0 = x+2*e;
k = 0;
while abs(x0-x)>e & k<N
    k = k+1;
    x0=x;
    x=x0-feval(f,x0)/feval(fd,x0);
    fprintf("x=%f\n", x);
end

if k==N
    warning('超过最大迭代次数限制');

end

