function [time,RW_power] = calc_RW_power(timeRW, powerRW, p_idle, n, m, t0, t_n, t_m)
% Creates vector for time and power consumption
%   n: number of RW activations separated by small time
%   m: number of RW activations separated by large time
%   t0: time to wait before first RW activation (seconds)
%   tn: time between consecutive n RW activations (seconds)
%   tm: time between m groups of n RW activations (seconds)
%   p_idle: Idle power consumption of RW
%RW required power
tpulse=timeRW';
ppulse=powerRW';

time = [0, t0-1];
RW_power = [0, 0];
%plot(time,RW_power)

for i=1:n
    %time = horzcat( time, t0+(i-1)*(t_n+d_h+d_t+3)+tpulse );
    time = horzcat( time, t0+(i-1)*(t_n+3)+tpulse );
    %time(1,2+7*i)=time(1,2+7*i)-1;
    RW_power = horzcat( RW_power, ppulse );
end

%time=horzcat(time,n*t_n+t_m+t0);
time=horzcat(time,n*t_n+t_m+t0-3);
RW_power=horzcat(RW_power,0);

if m>1
    m=m-1;
    for i=1:m
        time = horzcat( time, (n*t_n+t_m+t0)*m+time );
        %time(1,(2+7*n+2)*i)=time(1,(2+7*n+2)*i)-2;
        RW_power = horzcat( RW_power, RW_power );
    end
end
RW_power=RW_power+p_idle;
%plot(time,RW_power,'r')

end