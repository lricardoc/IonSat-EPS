stat=[rx;ry;rz;vx;vy;vz]; %pos and vel in inertial frame
%functions: gst, inertial_to_terrestrial, djm, time_to_dayf
% Ephemerides date in Modified Julian date:
year = 2020;
mjd = djm(1, 1, year);     % Format (day, month, year)
% mjdo = djm(1, 1, year);     % modified julian date of 1/1/year
% mjd1 = djm(1, 1, year+1);   % modified julian date of 1/1/(year+1)
% year_frac = year + (mjd - mjdo)/(mjd1 - mjdo);  % year and fraction

% Ephemerides time:
dfra = time_to_dayf (0, 00, 00);    % UTC time in (hour=12, minute=0, sec=0)

% t is the time in seconds after january 1, 1, 2006 where we want the conversion
t = 0:10:100; %10 seconds after 12:00:00
% To convert from inertial state vector to terrestrial vector
        geoc = inertial_to_terrestrial(gst(mjd, dfra+t), stat);
        
        
        
gst(mjd, dfra+t)