function [time,thrust_power] = calc_thrust_power(p_peak,p_heat,p_idle, d_h, d_t, n, m, t0, t_n, t_m)
% Creates vector for time and power consumption
%   n: number of thrusts separated by small time
%   m: number of thrusts separated by large time
%   t0: time to wait before first thrust (seconds)
%   tn: time between consecutive n thrust (seconds)
%   tm: time between m groups of n thrust (seconds)
%   p_xxx: power in Watts 
%   d_h: duration heating time (seconds)
%   d_t: duration thrust time (seconds)
%Thruster required power
tpulse=[0, 1,     1+d_h, 2+d_h, 2+d_h+d_t,d_h+d_t+3, d_h+d_t+3+t_n];
ppulse=[0, p_heat,p_heat,p_peak,p_peak,   0, 0];
%plot(tpulse,ppulse)
% time = horzcat([0, t0], t0+tpulse, t0+t_n+tpulse, t0+2*t_n+tpulse);
% thrust_power = horzcat([0, 0], ppulse, ppulse, ppulse);
time = [0, t0-1];
thrust_power = [0, 0];
for i=1:n
    %time = horzcat( time, t0+(i-1)*(t_n+d_h+d_t+3)+tpulse );
    time = horzcat( time, t0+(i-1)*(t_n+d_h+d_t+3)+tpulse );
    time(1,2+7*i)=time(1,2+7*i)-1;
    thrust_power = horzcat( thrust_power, ppulse );
end

%time=horzcat(time,n*t_n+t_m+t0);
time=horzcat(time,n*t_n+t_m+t0-3);
thrust_power=horzcat(thrust_power,0);

if m>1
    m=m-1;
    for i=1:m
        time = horzcat( time, (n*t_n+t_m+t0)*m+time );
        %time(1,18*i)=time(1,18*i)-2;
        time(1,(2+7*n+2)*i)=time(1,(2+7*n+2)*i)-2;
        thrust_power = horzcat( thrust_power, thrust_power );
    end
end
thrust_power=thrust_power+p_idle;
%plot(time,thrust_power,'r')

end