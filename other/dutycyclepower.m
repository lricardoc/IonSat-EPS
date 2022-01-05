t_heat=20*60; %heat time in seconds
t_thrust=50*60; %thrust time in seconds
%t_charge=22500:500:45000; %heat time in seconds
t_charge=20000:50:45000; %heat time in seconds
eff_batt2thruster=0.9;

duty_cycle_power=(t_heat+t_thrust)./(t_heat+t_thrust+t_charge);
P_thruster=(duty_cycle_power*50+(1-duty_cycle_power)*0.32)/eff_batt2thruster;
%P_bus=(P_thruster+13.16)/0.85;
%P_bus=(P_thruster+12.96)/0.85;
%P_bus=(P_thruster+0.03*(9.77+4.79)+(1-duty_cycle_power-0.03)*(7.13+4.5))/0.85;
P_bus=(P_thruster+0.03*(19.77+4.79)+(1-duty_cycle_power-0.03)*(7.13+4.5))/0.85;

figure()
subplot(2,2,1)
set(gcf,'color','w');
plot(t_charge/60,duty_cycle_power*100)
hold on
grid on
ylabel('Duty Cycle Thruster [%]')
xlabel('Time to recharge [min]')
title('Thruster Duty cycle as a function of recharge time')
subplot(2,2,3)
set(gcf,'color','w');
plot(t_charge,duty_cycle_power*100)
hold on
grid on
ylabel('Duty Cycle Thruster [%]')
xlabel('Time to recharge [seconds]')

subplot(2,2,2)
set(gcf,'color','w');
plot(duty_cycle_power*100,P_thruster)
hold on
grid on
xlabel('Duty Cycle Thruster [%]')
ylabel('Power Thruster [W]')
subplot(2,2,4)
set(gcf,'color','w');
plot(duty_cycle_power*100,P_bus)
hold on
grid on
yline(20.09, 'r-.')
yline(22.6118, 'g-.')
yline(25.44,'c-.')
yline(27.04,'m-.')
xlabel('Duty Cycle Thruster [%]')
ylabel('Power Consumption Platform [W]')
title('Platform power average consumption per orbit at 300 km')
legend('Power function of duty cycle','Power generated 300km β=25°','Power generated 300km β=35°','Power generated 300km β=45°','Power generated 300km β=50°')


% set(gcf,'color','w');
% plot(duty_cycle_power*100,P_bus, 'LineWidth',2)
% hold on
% grid on
% yline(22.6118, 'g-.', 'LineWidth',2)
% yline(25.44,'c-.', 'LineWidth',2)
% yline(27.04,'m-.', 'LineWidth',2)
% xlabel('Duty Cycle Thruster [%]')
% ylabel('Power Consumption Platform [W]')
% title('Platform power average consumption per orbit')
% legend('Power function of duty cycle','Power generated 300km β=25°','Power generated 300km β=35°','Power generated 300km β=45°','Power generated 300km β=50°')




powerbeta=fit(Pav',B','cubicinterp'); %
%plot(powerbeta,B,Pav)
plot(powerbeta)
hold on
grid on
xlabel('Power Generated [W]')
ylabel('Beta Angle [W]')

%% get power average 
load('Power_av_beta.mat')
B=0:1:89;
figure()
plot(B,Pav(1,:))
hold on;
plot(B,Pav(2,:),'r')
plot(B,Pav(3,:),'m')
plot(B,Pav(4,:),'c')
legend('Beta vs Power Average, 300km Altitude','Beta vs Power Average, 400km Altitude','Beta vs Power Average, 500km Altitude','Beta vs Power Average, 600km Altitude')
%title('Power Loads')
ylabel('Power Average [W]')
xlabel('Beta [deg]')
grid on

%% second plot
t_heat=20*60; %heat time in seconds
t_thrust=50*60; %thrust time in seconds
%t_charge=22500:500:45000; %heat time in seconds
t_charge=20000:50:45000; %heat time in seconds
eff_batt2thruster=0.9;

duty_cycle_power=(t_heat+t_thrust)./(t_heat+t_thrust+t_charge);
P_thruster=(duty_cycle_power*50+(1-duty_cycle_power)*0.32)/eff_batt2thruster;
%P_bus=(P_thruster+13.16)/0.85;
%P_bus=(P_thruster+12.96)/0.85;
%P_bus=(P_thruster+0.03*(9.77+4.79)+(1-duty_cycle_power-0.03)*(7.13+4.5))/0.85;
P_bus=(P_thruster+0.03*(19.77+4.79)+(1-duty_cycle_power-0.03)*(7.13+4.5))/0.85;

figure()
set(gcf,'color','w');
plot(duty_cycle_power*100,P_bus, 'LineWidth',2)
hold on
grid on
yline(18.92, 'm-.', 'LineWidth',2)
yline(20.06, 'g-.', 'LineWidth',2)
yline(21.27, 'y-.', 'LineWidth',2)
yline(22.56,'c-.', 'LineWidth',2)
yline(23.93,'r-.', 'LineWidth',2)
xlabel('Duty Cycle Thruster [%]')
ylabel('Power Consumption Platform [W]')
title('Platform power average consumption per orbit')
legend('Power function of duty cycle','Power generated 300km β=20°','Power generated 300km β=25°','Power generated 300km β=30°','Power generated 300km β=35°','Power generated 300km β=40°')

