%CIC writer modified from IonSat -> LoLaSat to use with CICdata.slx (EPS)
disp('Opening out file');

data.Sun_angle_SA = out.Sun_angle_SA;   %in degrees
%data.Satellite_eclipse = out.eclipse;   %0: 0% eclipse 1: 100% eclipse
%data.Satellite_eclipse.Time = out.eclipse.Time;   %0: 0% eclipse 1: 100% eclipse
%data.Satellite_eclipse.Data = double(out.eclipse.Data);   %0: 0% eclipse 1: 100% eclipse
data.Satellite_eclipse = out.eclipse1;   %0: 0% eclipse 1: 100% eclipse
data.Earth_angle = out.Earth_angle;     %in degrees
data.Altitude = out.alt;                %in Km
data.Earth_direction_BRF = out.Earth_direction; %cosine director
data.Sun_direction_BRF = out.Sun_direction;     %cosine director
data.Geo_coordinates = out.LL;          %Latitude and Longitude in degrees
data.Pload = out.TOTAL_LOAD;          %Total platform power consumption

data.time = num2cell(datetime(out.T_JD.data,'convertfrom','juliandate','Format','yyyy-MM-dd''T''HH:mm:ss'));

%%METADATA CREATION

disp('Writing metadata');

%MEM METADATA 
metadata.Format = 'yyyy-MM-ddTHH:mm:ss';
metadata.creationTime = datestr(now,metadata.Format);
metadata.objectName = 'LOLASAT';
metadata.objectID = 'LOLASAT ZFT';
metadata.userprotocol = ' CIC';
%metadata.usercontent = 'SUN_ANGLE_SA_1'; %needs to be replicated for all cases
metadata.timeSystem = 'UTC';

% %1. SUN ANGLE METADATA
% fileID = fopen('./CICData/data_sun_angle.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 1.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = SUN_ANGLE_SA_1','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);
% 
% %2. SATELLITE ECLIPSE METADATA
% fileID = fopen('./CICData/data_eclipse.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 2.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = SATELLITE_ECLIPSE','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);
% 
% %3. EARTH ANGLE METADATA
% fileID = fopen('./CICData/data_earth_angle.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 1.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = EARTH_ANGLE_SA_1','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);
% 
% %4. SATELLITE ALTITUDE METADATA
% fileID = fopen('./CICData/data_sat_alt.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 1.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = SATELLITE_ALTITUDE','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);
% 
% %5. EARTH DIRECTION METADATA
% fileID = fopen('./CICData/data_earth_dir.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 1.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = EARTH_DIRECTION-SATELLITE_FRAME','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);
% 
% %6. SUN DIRECTION METADATA
% fileID = fopen('./CICData/data_sun_dir.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 1.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = SUN_DIRECTION-SATELLITE_FRAME','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);
% 
% %7. GEOGRAPHICAL COORDINATES METADATA
% fileID = fopen('./CICData/data_geo_latlon.txt','w');
% fprintf(fileID,'CIC_MEM_VERS = 1.0\r\n');
% fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
% fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_START\r\n');
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
% fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
% fprintf(fileID,strcat('USER_DEFINED_CONTENT = GEOGRAPHICAL_COORDINATES','\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
% fprintf(fileID,'\r\n');
% fprintf(fileID,'META_STOP\r\n');
% fprintf(fileID,'\r\n');
% fclose(fileID);

%8. TOTAL PLATFORM POWER CONSUMPTION
fileID = fopen('./CICData/data_p_loads.txt','w');
fprintf(fileID,'CIC_MEM_VERS = 2.0\r\n');
fprintf(fileID,strcat('CREATION_DATE = ',metadata.creationTime,'\r\n'));
fprintf(fileID,'ORIGINATOR = LOLASAT ZFT\r\n');
fprintf(fileID,'\r\n');
fprintf(fileID,'META_START\r\n');
fprintf(fileID,'\r\n');
fprintf(fileID,strcat('OBJECT_NAME = ',metadata.objectName,'\r\n'));
fprintf(fileID,strcat('OBJECT_ID = ',metadata.objectID,'\r\n'));
fprintf(fileID,strcat('USER_DEFINED_PROTOCOL = ',metadata.userprotocol,'\r\n'));
fprintf(fileID,strcat('USER_DEFINED_CONTENT = SATELLITE_CONSUMED_POWER','\r\n'));
fprintf(fileID,'\r\n');
fprintf(fileID,strcat('TIME_SYSTEM = ',metadata.timeSystem,'\r\n'));
fprintf(fileID,'\r\n');
fprintf(fileID,'META_STOP\r\n');
fprintf(fileID,'\r\n');
fclose(fileID);

%%METADATA END

%% writing DATA
data.table_CIC_Sun_angle = [data.time num2cell(data.Sun_angle_SA.Data)];
data.table_CIC_eclipse = [data.time num2cell(data.Satellite_eclipse.Data)];
data.table_CIC_Earth_angle = [data.time num2cell(data.Earth_angle.Data)];
data.table_CIC_Sat_alt = [data.time num2cell(data.Altitude.Data)];
data.table_CIC_Earth_direction = [data.time num2cell(data.Earth_direction_BRF.Data)];
data.table_CIC_Sun_direction = [data.time num2cell(data.Sun_direction_BRF.Data)];
data.table_CIC_Geo_coordinates = [data.time num2cell(data.Geo_coordinates.Data)];
data.table_CIC_P_loads = [data.time num2cell(data.Pload.Data)];

%Writing temporal files
disp('Writing Sun angle');
writecell(data.table_CIC_Sun_angle,'./CICData/tmp_sun_angle.txt','Delimiter',' ');
disp('Writing eclipse fraction');
writecell(data.table_CIC_eclipse,'./CICData/tmp_eclipse.txt','Delimiter',' ');
% disp('Writing Earth angle');
% writecell(data.table_CIC_Earth_angle,'./CICData/tmp_earth_angle.txt','Delimiter',' ');
% disp('Writing Satellite altitude');
% writecell(data.table_CIC_Sat_alt,'./CICData/tmp_sat_alt.txt','Delimiter',' ');
% disp('Writing Earth direction from Sat.');
% writecell(data.table_CIC_Earth_direction,'./CICData/tmp_earth_dir.txt','Delimiter',' ');
% disp('Writing Sun direction from Sat.');
% writecell(data.table_CIC_Sun_direction,'./CICData/tmp_sun_dir.txt','Delimiter',' ');
% disp('Writing Geographical coordinates');
% writecell(data.table_CIC_Geo_coordinates,'./CICData/tmp_geo_latlon.txt','Delimiter',' ');
disp('Writing Power loads');
writecell(data.table_CIC_P_loads,'./CICData/tmp_p_loads.txt','Delimiter',' ');

%%ADD METADATA TO THE EXPORT FILES

disp('Adding data to metadata file');

%copyfile('./CICData/data_eclipse.txt','./CICData/data_earth_angle.txt');

fileID = fopen('./CICData/data_sun_angle.txt','a');
fprintf(fileID, fileread('./CICData/tmp_sun_angle.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_eclipse.txt','a');
fprintf(fileID, fileread('./CICData/tmp_eclipse.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_earth_angle.txt','a');
fprintf(fileID, fileread('./CICData/tmp_earth_angle.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_sat_alt.txt','a');
fprintf(fileID, fileread('./CICData/tmp_sat_alt.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_earth_dir.txt','a');
fprintf(fileID, fileread('./CICData/tmp_earth_dir.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_sun_dir.txt','a');
fprintf(fileID, fileread('./CICData/tmp_sun_dir.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_geo_latlon.txt','a');
fprintf(fileID, fileread('./CICData/tmp_geo_latlon.txt'));
fclose(fileID);
fileID = fopen('./CICData/data_p_loads.txt','a');
fprintf(fileID, fileread('./CICData/tmp_p_loads.txt'));
fclose(fileID);


disp('Done!');
% copyfile("./Data/data_pos&speed.txt","C:\CNES\Vts-WindowsNT-32bits-3.5.1\Data\IonSat") %The destination directory might be changed