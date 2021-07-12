%% TEST for BATTERY DISCHARGE %%
tsimulation=60*45;   %in [s]

Cbat=2.6; %Cell capacity in [Ah]
%Battery configuration
Nbs=4;
Nbp=4;
C=Cbat*Nbp*3600; %in [Ampere*sec]

%constant current discharge
DOD_0=0;    %initial DOD from 0 to 1
Pload=50;    %Load required power [W]
iLoad=2;    %in [A]

eff_i1=0.9;

battery_dis
sim('battery_dis');

%% TEST for BATTERY CHARGE %%
tsimulation=60*70;   %in [s]

Cbat=2.6; %Cell capacity in [Ah]
%Battery configuration
Nbs=4;
Nbp=4;
C=Cbat*Nbp*3600; %in [Ampere*sec]

%constant current charge
SOC_0=0;    %initial DOD from 0 to 1
iCharge=8;    %in [A]

eff_bc=0.9;

battery_char
sim('battery_char');


%% TEST EPS_SIM
Torbit=90*60;
tsimulation=60*45;   %in [s]
tsimulation=Torbit;

Cbat=2.6;           %Cell capacity in [Ah]
%Battery configuration
Nbs=4;
Nbp=4;
C=Cbat*Nbp*3600;    %Battery Capacity for all parallel arrays [Ampere*sec]

%Loads
Pload1=50;          %Required power Thruster [W]
iLoad=2;     %to test, in [A]
Pload2=2;           %Required power OBC [W]
Pload3=3;           %Required power RWA [W]

eff_i1=0.9;         %efficiency PDU CH not regulated
eff_i2=0.85;        %efficiency PDU CH 3.3V

%Power Generation
Psa=48;             %Peak power generation
eff_ACU=0.85;        %efficiency ACU conversion


%Battery
DOD_0=0;            %initial DOD from 0 to 1
iB=2;   %to test in [A]

%Charge/Discharge logic
I_BD_max= 8;
I_BC_max= 3;
 
EPS_sim_test
E=sim('EPS_sim_test');

time = E.tout;
DOD = getdatasamples(E.DOD,(1:length(time)));
Vbat = getdatasamples(E.Vbat,(1:length(time)));
Ibat = getdatasamples(E.Ibat,(1:length(time)));


