%% first attempts, not used anymore
t_heat=20*60; %heat time in seconds
t_thrust=50*60; %thrust time in seconds
%t_charge=22500:500:45000; %heat time in seconds
t_charge=20000:50:45000; %heat time in seconds
eff_batt2thruster=0.9;

duty_cycle_thruster=(t_thrust)./(t_heat+t_thrust+t_charge);
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

%% second plot (not used anymore)
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

%% Plots for Orbit report
clear

t_heat=16*60; %heat time in seconds
t_thrust=50*60; %thrust time in seconds
%t_charge=22500:500:45000; %recharge batteries time in seconds
t_charge=20000:50:45000; %recharge batteries time in seconds
eff_batt2thruster=0.9;  %Battery to thruster efficiency

duty_cycle_thruster=(t_thrust)./(t_heat+t_thrust+t_charge); %this is the real % of time the thruster will propel the satellite
duty_cycle_power=(t_heat+t_thrust)./(t_heat+t_thrust+t_charge); %because the power consumption is also there when the thruster is heating
%t_charge_calc=t_thrust./duty_cycle_thruster-t_heat-t_thrust;

%the following is the average propulsion power by cycle
P_thruster=(duty_cycle_power*50+(1-duty_cycle_power)*0.32)/eff_batt2thruster;
%P_bus=(P_thruster+0.03*(19.77+4.79)+(1-duty_cycle_power-0.03)*(7.13+4.5))/0.85;
P_nominal=9.82+6.02; %Nominal mode power + Margin [W] FROM POWER BUDGET
P_com=21.15+7.04; %Com mode power + Margin [W]
P_bus=(P_thruster+P_nominal*duty_cycle_power+0.03*P_com+(1-duty_cycle_power-0.03)*P_nominal);
%P_bus=(P_thruster+0.03*P_com+(1-0.03)*P_nominal);


%for the last plot only
load('power_from_beta_and_altitude.mat')
B_Pbus_required = interp1(Pav(1,:),B(1,:),P_bus);     %Interpolation for altitude 300km
% B2 = interp1(Pav(2,:),B(2,:),Pav1);
% B3 = interp1(Pav(3,:),B(3,:),Pav1);
% B4 = interp1(Pav(4,:),B(4,:),Pav1);
B30=interp1(B(1,:),Pav(1,:),30); %Power at beta angle = 30 degrees
B35=interp1(B(1,:),Pav(1,:),35); 
B45=interp1(B(1,:),Pav(1,:),45); 
B50=interp1(B(1,:),Pav(1,:),50); 
P22=interp1(Pav(1,:),B(1,:),22); %Beta angle at power = 22 W
P24=interp1(Pav(1,:),B(1,:),24);
P26=interp1(Pav(1,:),B(1,:),26);



figure()
set(gcf,'color','w');
subplot(2,2,1)
    plot((t_charge+t_heat)/60,duty_cycle_thruster*100)
    hold on
    grid on
    ylabel('Duty Cycle Thruster [%]')
    xlabel('Time before two thrusts (charging + heating) [min]')
    title('Thruster Duty cycle as a function of recharge time')
subplot(2,2,2)
    plot(duty_cycle_thruster*100,P_thruster)
    hold on
    grid on
    xlabel('Duty Cycle Thruster [%]')
    ylabel('Power Thruster [W]')
    title('Average power consumption by Thruster Duty cycle')
subplot(2,2,3)
    plot(duty_cycle_thruster*100,P_bus)
    hold on
    grid on
    yline(B30, 'r-.','LineWidth',1)
    yline(B35, 'g-.','LineWidth',1)
    yline(B45, 'c-.','LineWidth',1)
    yline(B50, 'm-.','LineWidth',1)
    xlabel('Duty Cycle Thruster [%]')
    ylabel('Power Consumption [W]')
    title('Platform power average consumption as function of duty cycle')
    legend('Platform Power Consumption','Power generated 300km β=30°','Power generated 300km β=35°','Power generated 300km β=45°','Power generated 300km β=50°')
subplot(2,2,4)
%What I need: from a certain duty cycle: know what is the required BETA
    plot(duty_cycle_thruster*100,B_Pbus_required)
    hold on
    grid on
    yline(P22, 'r-.','LineWidth',1)
    yline(P24, 'g-.','LineWidth',1)
    yline(P26, 'm-.','LineWidth',1)
    xlabel('Duty Cycle Thruster [%]')
    ylabel('Minimum Beta [deg]')
    title('Minimum Beta required for a Duty Cycle at 300 km')
    legend('Beta required as function of duty cycle','β angle with Power generated = 22W','β angle with Power generated = 24W','β angle with Power generated = 26W' )

%From a certain power consumption: know what is the required BETA
figure()
set(gcf,'color','w');
    plot(P_bus,B_Pbus_required)
    hold on
    grid on
    yline(P22, 'r-.','LineWidth',1)
    yline(P24, 'g-.','LineWidth',1)
    yline(P26, 'm-.','LineWidth',1)
    xlabel('Power Consumption Bus [W]')
    ylabel('Minimum Beta [deg]')
    title('Minimum Beta required for bus power consumption at 300 km')
    legend('Beta required as function of duty cycle','β angle with Power generated = 22W','β angle with Power generated = 24W','β angle with Power generated = 26W' )

%% Plots to send Jerome
clear

t_heat=16*60; %heat time in seconds
t_thrust=50*60; %thrust time in seconds
%t_charge=22500:500:45000; %recharge batteries time in seconds
t_charge=10000:50:300000; %recharge batteries time in seconds
eff_batt2thruster=0.9;  %Battery to thruster efficiency

duty_cycle_thruster=(t_thrust)./(t_heat+t_thrust+t_charge); %this is the real % of time the thruster will propel the satellite
duty_cycle_power=(t_heat+t_thrust)./(t_heat+t_thrust+t_charge); %because the power consumption is also there when the thruster is heating
%t_charge_calc=t_thrust./duty_cycle_thruster-t_heat-t_thrust;

%the following is the average propulsion power by cycle
P_thruster=(duty_cycle_power*50+(1-duty_cycle_power)*0.32)/eff_batt2thruster;
%P_bus=(P_thruster+0.03*(19.77+4.79)+(1-duty_cycle_power-0.03)*(7.13+4.5))/0.85;
P_nominal=9.82+6.02; %Nominal mode power + Margin [W] FROM POWER BUDGET
P_com=21.15+7.04; %Com mode power + Margin [W]
P_bus=(P_thruster+P_nominal*duty_cycle_power+0.03*P_com+(1-duty_cycle_power-0.03)*P_nominal);
%P_bus=(P_thruster+0.03*P_com+(1-0.03)*P_nominal);


%for the last plot only
load('power_from_beta_and_altitude.mat')
B_Pbus_required = interp1(Pav(1,:),B(1,:),P_bus);     %Interpolation for altitude 300km
% B2 = interp1(Pav(2,:),B(2,:),Pav1);
% B3 = interp1(Pav(3,:),B(3,:),Pav1);
% B4 = interp1(Pav(4,:),B(4,:),Pav1);
B30=interp1(B(1,:),Pav(1,:),30); %Power at beta angle = 30 degrees
B35=interp1(B(1,:),Pav(1,:),35); 
B45=interp1(B(1,:),Pav(1,:),45); 
B50=interp1(B(1,:),Pav(1,:),50); 
P22=interp1(Pav(1,:),B(1,:),22); %Beta angle at power = 22 W
P24=interp1(Pav(1,:),B(1,:),24);
P26=interp1(Pav(1,:),B(1,:),26);



figure()
set(gcf,'color','w');
subplot(2,2,1)
    plot((t_charge+t_heat)/60,duty_cycle_thruster*100)
    hold on
    grid on
    ylabel('Duty Cycle Thruster [%]')
    xlabel('Time before two thrusts (charging + heating) [min]')
    title('Thruster Duty cycle as a function of recharge time')
subplot(2,2,2)
    plot(duty_cycle_thruster*100,P_thruster)
    hold on
    grid on
    xlabel('Duty Cycle Thruster [%]')
    ylabel('Power Thruster [W]')
    title('Average power consumption by Thruster Duty cycle')
subplot(2,2,3)
    plot(duty_cycle_thruster*100,P_bus)
    hold on
    grid on
    yline(B30, 'r-.','LineWidth',1)
    yline(B35, 'g-.','LineWidth',1)
    yline(B45, 'c-.','LineWidth',1)
    yline(B50, 'm-.','LineWidth',1)
    xlabel('Duty Cycle Thruster [%]')
    ylabel('Power Consumption [W]')
    title('Platform power average consumption as function of duty cycle')
    legend('Platform Power Consumption','Power generated 300km β=30°','Power generated 300km β=35°','Power generated 300km β=45°','Power generated 300km β=50°')
subplot(2,2,4)
%What I need: from a certain duty cycle: know what is the required BETA
    plot(duty_cycle_thruster*100,B_Pbus_required)
    hold on
    grid on
    yline(P22, 'r-.','LineWidth',1)
    yline(P24, 'g-.','LineWidth',1)
    yline(P26, 'm-.','LineWidth',1)
    xlabel('Duty Cycle Thruster [%]')
    ylabel('Minimum β [deg]')
    title('Minimum β required for a Duty Cycle at 300 km')
    legend('Beta required as function of duty cycle','β angle with Power generated = 22W','β angle with Power generated = 24W','β angle with Power generated = 26W' )

%From a certain power consumption: know what is the required BETA
figure()
set(gcf,'color','w');
    plot(P_bus,B_Pbus_required)
    hold on
    grid on
    yline(P22, 'r-.','LineWidth',1)
    yline(P24, 'g-.','LineWidth',1)
    yline(P26, 'm-.','LineWidth',1)
    xlabel('Power Consumption Bus [W]')
    ylabel('Minimum Beta [deg]')
    title('Minimum Beta required for bus power consumption at 300 km')
    legend('Beta required as function of duty cycle','β angle with Power generated = 22W','β angle with Power generated = 24W','β angle with Power generated = 26W' )

    
    
    
    
    
    
%% OK to plot beta and other angles for ISS orbit
% filename = 'ISSbeta.txt';
% delimiterIn = ' ';
% headerlinesIn = 4;
datatemp = importdata('ISSbeta.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   bISS(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   days(i+1)=daysz(k+1);
end
datatemp = importdata('ISSaltitude.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   altISS(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
datatemp = importdata('ISSecc.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   eccISS(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
datatemp = importdata('ISSfuel.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   fuelISS(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
%% now let's check for ISS orbit
%clear
load('power_from_beta_and_altitude.mat')
load('ISS_GMAT.mat')
P_ISS=interp1(B(1,:),Pav(1,:),abs(bISS)); 
%the duty cycle cannot be more than duty_max, otherwise, not enough power
duty_max=interp1(B_Pbus_required,duty_cycle_thruster*100,abs(bISS));
t_charge_max=(((t_thrust)./(duty_max/100))-(t_heat+t_thrust))/60;
%duty_cycle_thruster=((t_thrust)./(t_heat+t_thrust+t_charge))/60; %this is the real % of time the thruster will propel the satellite

figure()
set(gcf,'color','w');
subplot(2,2,1)
    plot(daysISS,bISS)
    hold on
    grid on
    title('Variation of β angle during mission deployed from ISS')
    xlabel('Mission time from deployment [days]')
    ylabel('β angle [deg]')
%yyaxis right
subplot(2,2,2)
    plot(daysISS,P_ISS)
    grid on
    title('Variation of power collected during mission deployed from ISS')
    xlabel('Mission time from deployment [days]')
    ylabel('Average Collected Power by orbit [w]')
subplot(2,2,3)
    plot(daysISS,duty_max)
    ylim([min(duty_max) max(duty_max)])
    xlabel('Mission time from deployment [days]')
    ylabel('Thruster Duty Cycle [%]')
    grid on
    title('Maximum duty cycle allowed for the thruster during mission deployed from ISS')
subplot(2,2,4)
    plot(daysISS,t_charge_max)
    ylim([min(t_charge_max) max(t_charge_max)])
    grid on
    xlabel('Mission time from deployment [days]')
    ylabel('Recharge time (including heating) [min]')
    yyaxis right
    ylim([min(t_charge_max)*60 max(t_charge_max)*60])
    title('Recharge time allowed for the thruster during mission deployed from ISS')
    ylabel('Recharge time (including heating) [s]')
%nanmean(t_charge_max*60)

figure()
set(gcf,'color','w');
subplot(2,1,1)
    plot(daysISS,altISS)
    hold on
    grid on
    title('Altitude during mission deployed from ISS')
%yyaxis right
subplot(2,1,2)
    plot(daysISS,movmean(altISS,10))
    grid on
    title('Moving mean (10 elements) of Altitude during mission deployed from ISS')
    
%% OK to plot beta and other angles for SSO orbit
% filename = 'ISSbeta.txt';
% delimiterIn = ' ';
% headerlinesIn = 4;
datatemp = importdata('SSObeta.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   bSSO(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   daysasdf(i+1)=daysSSO(k+1);
end
datatemp = importdata('SSOaltitude.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   altSSO(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
datatemp = importdata('SSOecc.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   eccSSO(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end
datatemp = importdata('SSOfuel.txt');
for i = 0:1:floor(length(datatemp.data)/100)-1
   k=100*i;
   fuelSSO(i+1)=datatemp.data(k+1);
   %days(i)=datatemp.textdata(k+4);
end

%% from SSO
load('power_from_beta_and_altitude.mat')
load('SSO_GMAT.mat')
P_SSO=interp1(B(1,:),Pav(1,:),abs(bSSO)); 
%the duty cycle cannot be more than duty_max, otherwise, not enough power
duty_max=interp1(B_Pbus_required,duty_cycle_thruster*100,abs(bSSO));
t_charge_max=(((t_thrust)./(duty_max/100))-(t_heat+t_thrust))/60;
%duty_cycle_thruster=((t_thrust)./(t_heat+t_thrust+t_charge))/60; %this is the real % of time the thruster will propel the satellite

figure()
set(gcf,'color','w');
subplot(2,2,1)
    plot(daysSSO,bSSO)
    hold on
    grid on
    title('Variation of β angle during mission deployed from SSO')
    xlabel('Mission time from deployment [days]')
    ylabel('β angle [deg]')
%yyaxis right
subplot(2,2,2)
    plot(daysSSO,P_SSO)
    grid on
    title('Variation of power collected during mission deployed from SSO')
    xlabel('Mission time from deployment [days]')
    ylabel('Average Collected Power by orbit [w]')
subplot(2,2,3)
    plot(daysSSO,duty_max)
    ylim([min(duty_max) max(duty_max)])
    xlabel('Mission time from deployment [days]')
    ylabel('Thruster Duty Cycle [%]')
    grid on
    title('Maximum duty cycle allowed for the thruster during mission deployed from SSO')
subplot(2,2,4)
    plot(daysSSO,t_charge_max)
    ylim([min(t_charge_max) max(t_charge_max)])
    grid on
    xlabel('Mission time from deployment [days]')
    ylabel('Recharge time (including heating) [min]')
    yyaxis right
    ylim([min(t_charge_max)*60 max(t_charge_max)*60])
    title('Recharge time allowed for the thruster during mission deployed from SSO')
    ylabel('Recharge time (including heating) [s]')
%nanmean(t_charge_max*60)

figure()
set(gcf,'color','w');
subplot(2,1,1)
    plot(daysSSO,altSSO)
    hold on
    grid on
    title('Altitude during mission deployed from ISS')
%yyaxis right
subplot(2,1,2)
    plot(daysSSO,movmean(altSSO,10))
    grid on
    title('Moving mean (10 elements) of Altitude during mission deployed from SSO')