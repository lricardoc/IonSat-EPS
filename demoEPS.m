Torbit=90*60;       %1 orbit approx. 90 minutes
%tsimulation=60*45;   %in [s] 1 orbit
tsimulation=8*Torbit;

%Battery configuration
Cbat=2.6;           %Cell capacity in [Ah]
Nbs=4;
Nbp=4;
C=Cbat*Nbp*3600;    %Battery Capacity for all parallel arrays [Ampere*sec]

%Loads
Pload1=50;          %Required power Thruster [W]
%iLoad=2;     %to test, in [A]
Pload2=2;           %Required power OBC [W]
Pload3=2.5;         %Required power ADCS w/o RWA [W]
Pload4=1.7;         %Required power Com (Rx)[W]

eff_i1=0.9;         %efficiency PDU CH not regulated
eff_i2=0.85;        %efficiency PDU CH 3.3V

%Power Generation
Psa=48;             %Peak power generation [W]
eff_ACU=0.85;       %efficiency ACU conversion
P_eps=0.6;          %internal power consumption EPS [W]


%Battery
DOD_0=0;            %initial DOD from 0 to 1
%iB=2;   %to test in [A]

%Charge/Discharge logic
I_BD_max= 5;        %Maximum discharge current [A] approx. C/2
I_BC_max= 3;        %Maximum charge current [A] approx. C/3.5
%inside the function:
% Vfull=16.8;     %full battery charge
% Vmax=16.6;      %maximum charge battery
% Vnorm=14;       %battery normal voltage
% Vsafe=13.4;      %minimum battery safe voltage
% Vcrit=13;       %critical battery voltage

EPS_sim_test
E=sim('EPS_sim_test');

time = E.tout;
DOD = getdatasamples(E.DOD,(1:length(time)));
Vbat = getdatasamples(E.Vbat,(1:length(time)));
Ibat = getdatasamples(E.Ibat,(1:length(time)));
SOC = 100*(1 - DOD);

ibc=zeros(length(time),1);
ibd=zeros(length(time),1);
for i=1:length(time)
    if Ibat(i)>0
        ibc(i,1)=0;
        ibd(i,1)=Ibat(i);
    end
    if Ibat(i)<0
        ibc(i,1)=-Ibat(i);
        ibd(i,1)=0;
    end
end


figure(1)
set(gcf,'color','w');
    subplot(2,2,1)
        plot(time,SOC,'b','LineWidth',1)
        hold on;
        legend('State of Charge [%]')
        title('4S 4P Battery State of Charge')
        ylabel('Charge %')
        xlabel('time in seconds')
        grid on
subplot(2,2,3)
        plot(time,Vbat,'b','LineWidth',1)
        hold on;
        plot(time(:,1),16.8,'--b.')
        plot(time(:,1),16.6,'--m.')
        plot(time(:,1),14.0,'--g.')
        plot(time(:,1),13.4,'--r.')
        plot(time(:,1),13.0,'--b.')
        legend('Battery array Voltage [V]','100%','Vmax','Vnormal','Vsafe','Vcritical')
        title('4S 4P Battery Voltage')
        ylabel('Voltage')
        xlabel('time in seconds')
        grid on
subplot(2,2,2)
        plot(time,ibc,'b','LineWidth',1)
        hold on;
         plot(time(:,1),1.04,'--b.')
         plot(time(:,1),0.52,'--g.')
         plot(time(:,1),2.08,'--r.')
        legend('Charge Current [A]','C/10','C/20','C/5')
        title('4S 4P Battery Charge Current')
        ylabel('Current [A]')
        xlabel('time in seconds')
        grid on
subplot(2,2,4)
        plot(time,ibd,'b','LineWidth',1)
        hold on;
        legend('Discharge Current [A]')
        title('4S 4P Battery Discharge Current')
        ylabel('Current [A]')
        xlabel('time in seconds')
        grid on
    