DOD=0:0.01:1;
Nbs=8;
for i=1:length(DOD)
Voltagebat(i)=VbatDOD([DOD(i) Nbs]);
end

plot(DOD,Voltagebat)
hold on
grid on
xlabel('Depth of Discharge (DOD)')
ylabel('Battert E Voltage (V)')