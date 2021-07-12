DOD=[0:0.01:1];
Nbs=4;
Vbat=zeros(length(DOD));

for i=1:length(DOD)
    Vbat(i)=VbatDOD([DOD(i) Nbs]);
end

figure()
set(gcf,'color','w');
plot (DOD,Vbat)
grid on