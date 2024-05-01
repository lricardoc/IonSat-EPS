DOD=0:0.01:1;
Nbs=1;
for i=1:length(DOD)
Voltagebat(i)=VbatDOD2([DOD(i) Nbs]);
end

plot(DOD,Voltagebat)
hold on
grid on
xlabel('Depth of Discharge (DOD)')
ylabel('Battery E Voltage (V)')