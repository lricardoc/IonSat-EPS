%% For Access 1
% Define file name
filename = 'access01.txt';

% Open the file and read the data
fid = fopen(filename, 'rt');

% Adjust the format specifier to properly parse fractional seconds and times
data = textscan(fid, '%d %s %d %d:%d:%f %d %s %d %d:%d:%f %f', 'Delimiter', ' ', 'MultipleDelimsAsOne', 1);
fclose(fid);

% Extract relevant data for start time
start_day = data{1};        % Start day
start_month = data{2};      % Start month (cell array of strings)
start_year = data{3};       % Start year
start_hour = data{4};       % Start hour
start_minute = data{5};     % Start minute
start_second = data{6};     % Start second

% Convert month names to month numbers
start_month_num = month(datetime(start_month, 'InputFormat', 'MMM'));

% Ensure all time components are integers
start_day = int32(start_day);
start_hour = int32(start_hour);
start_minute = int32(start_minute);
start_second = int32(start_second);

% Combine date and time for the start time using datetime
start_time = datetime(start_year, start_month_num, start_day, start_hour, start_minute, start_second);

% Extract relevant data for end time
end_day = data{7};          % End day
end_month = data{8};        % End month (cell array of strings)
end_year = data{9};         % End year
end_hour = data{10};        % End hour
end_minute = data{11};      % End minute
end_second = data{12};      % End second

% Convert month names to month numbers
end_month_num = month(datetime(end_month, 'InputFormat', 'MMM'));

% Ensure all time components are integers
end_day = int32(end_day);
end_hour = int32(end_hour);
end_minute = int32(end_minute);
end_second = int32(end_second);

% Combine date and time for the end time using datetime
end_time = datetime(end_year, end_month_num, end_day, end_hour, end_minute, end_second);

% Duration in seconds is already available
duration_seconds = data{13};

% Extract unique dates from start_time
unique_dates = unique(dateshift(start_time, 'start', 'day'));

% Pre-allocate for storing number of accesses and duration per day
num_accesses_per_day = zeros(length(unique_dates), 1);
duration_per_day = zeros(length(unique_dates), 1);

% Loop through each unique date
for i = 1:length(unique_dates)
    % Find indices of accesses on that date
    current_date = unique_dates(i);
    access_indices = find(dateshift(start_time, 'start', 'day') == current_date);
    
    % Store number of accesses for that date
    num_accesses_per_day(i) = length(access_indices);
    
    % Calculate the total duration for accesses on that date
    duration_per_day(i) = sum(duration_seconds(access_indices));
end

% Display the result
disp('Date          | Number of Accesses | Total Duration (seconds)');
disp('------------------------------------------------------------');
for i = 1:length(unique_dates)
    fprintf('%s | %d               | %.2f\n', datestr(unique_dates(i)), num_accesses_per_day(i), duration_per_day(i));
end

mean(duration_per_day)/mean(num_accesses_per_day)

binEdges1 = 300:15:600;
% Create a histogram
histogram(duration_per_day, binEdges1);
% Add title and labels
title('Histogram of access duration per day');
xlabel('Value');
ylabel('Frequency');

binEdges2 = 1:1:8;
% Create a histogram
histogram(num_accesses_per_day, binEdges2);
% Add title and labels
title('Histogram of access number per day');
xlabel('Value');
ylabel('Frequency');

%% For Access 2
% Define file name
filename = 'access02.txt';

% Open the file and read the data
fid = fopen(filename, 'rt');

% Adjust the format specifier to properly parse fractional seconds and times
data = textscan(fid, '%d %s %d %d:%d:%f %d %s %d %d:%d:%f %f', 'Delimiter', ' ', 'MultipleDelimsAsOne', 1);
fclose(fid);

% Extract relevant data for start time
start_day = data{1};        % Start day
start_month = data{2};      % Start month (cell array of strings)
start_year = data{3};       % Start year
start_hour = data{4};       % Start hour
start_minute = data{5};     % Start minute
start_second = data{6};     % Start second

% Convert month names to month numbers
start_month_num = month(datetime(start_month, 'InputFormat', 'MMM'));

% Ensure all time components are integers
start_day = int32(start_day);
start_hour = int32(start_hour);
start_minute = int32(start_minute);
start_second = int32(start_second);

% Combine date and time for the start time using datetime
start_time = datetime(start_year, start_month_num, start_day, start_hour, start_minute, start_second);

% Extract relevant data for end time
end_day = data{7};          % End day
end_month = data{8};        % End month (cell array of strings)
end_year = data{9};         % End year
end_hour = data{10};        % End hour
end_minute = data{11};      % End minute
end_second = data{12};      % End second

% Convert month names to month numbers
end_month_num = month(datetime(end_month, 'InputFormat', 'MMM'));

% Ensure all time components are integers
end_day = int32(end_day);
end_hour = int32(end_hour);
end_minute = int32(end_minute);
end_second = int32(end_second);

% Combine date and time for the end time using datetime
end_time = datetime(end_year, end_month_num, end_day, end_hour, end_minute, end_second);

% Duration in seconds is already available
duration_seconds = data{13};

% Extract unique dates from start_time
unique_dates = unique(dateshift(start_time, 'start', 'day'));

% Pre-allocate for storing number of accesses and duration per day
num_accesses_per_day = zeros(length(unique_dates), 1);
duration_per_day = zeros(length(unique_dates), 1);

% Loop through each unique date
for i = 1:length(unique_dates)
    % Find indices of accesses on that date
    current_date = unique_dates(i);
    access_indices = find(dateshift(start_time, 'start', 'day') == current_date);
    
    % Store number of accesses for that date
    num_accesses_per_day(i) = length(access_indices);
    
    % Calculate the total duration for accesses on that date
    duration_per_day(i) = sum(duration_seconds(access_indices));
end

% Display the result
disp('Date          | Number of Accesses | Total Duration (seconds)');
disp('------------------------------------------------------------');
for i = 1:length(unique_dates)
    fprintf('%s | %d               | %.2f\n', datestr(unique_dates(i)), num_accesses_per_day(i), duration_per_day(i));
end

mean(duration_per_day)/mean(num_accesses_per_day)

binEdges1 = 2200:30:3000; %from 1200 to show all
% Create a histogram
histogram(duration_per_day, binEdges1);
% Add title and labels
title('Histogram of access duration per day');
xlabel('Value');
ylabel('Frequency');

binEdges2 = 4:1:9;
% Create a histogram
histogram(num_accesses_per_day, binEdges2);
% Add title and labels
title('Histogram of access number per day');
xlabel('Value');
ylabel('Frequency');

%% interesection of times
% Load data from access01.txt
fileID1 = fopen('access01.txt', 'r');
data01 = textscan(fileID1, '%d %s %d %d:%d:%f %d %s %d %d:%d:%f %f', 'Delimiter', ' ', 'MultipleDelimsAsOne', 1);
fclose(fileID1);

% Load data from access02.txt
fileID2 = fopen('access02.txt', 'r');
data02 = textscan(fileID2, '%d %s %d %d:%d:%f %d %s %d %d:%d:%f %f', 'Delimiter', ' ', 'MultipleDelimsAsOne', 1);
fclose(fileID2);

% Extract and process start and end times for access01
start_day1 = data01{1}; start_month1 = data01{2}; start_year1 = data01{3};
start_hour1 = data01{4}; start_minute1 = data01{5}; start_second1 = data01{6};
end_day1 = data01{7}; end_month1 = data01{8}; end_year1 = data01{9};
end_hour1 = data01{10}; end_minute1 = data01{11}; end_second1 = data01{12};
duration1 = data01{13};

% Convert start and end times for access01 to datetime
start_month_num1 = month(datetime(start_month1, 'InputFormat', 'MMM'));
start_time1 = datetime(start_year1, start_month_num1, start_day1, start_hour1, start_minute1, start_second1);
end_month_num1 = month(datetime(end_month1, 'InputFormat', 'MMM'));
end_time1 = datetime(end_year1, end_month_num1, end_day1, end_hour1, end_minute1, end_second1);

% Extract and process start and end times for access02
start_day2 = data02{1}; start_month2 = data02{2}; start_year2 = data02{3};
start_hour2 = data02{4}; start_minute2 = data02{5}; start_second2 = data02{6};
end_day2 = data02{7}; end_month2 = data02{8}; end_year2 = data02{9};
end_hour2 = data02{10}; end_minute2 = data02{11}; end_second2 = data02{12};
duration2 = data02{13};

% Convert start and end times for access02 to datetime
start_month_num2 = month(datetime(start_month2, 'InputFormat', 'MMM'));
start_time2 = datetime(start_year2, start_month_num2, start_day2, start_hour2, start_minute2, start_second2);
end_month_num2 = month(datetime(end_month2, 'InputFormat', 'MMM'));
end_time2 = datetime(end_year2, end_month_num2, end_day2, end_hour2, end_minute2, end_second2);

% Initialize a cell array to hold the intersecting rows from access02
intersected_data = {};

% Loop over each row of access01 and access02 to check for intersections
for i = 1:length(start_time1)
    for j = 1:length(start_time2)
        % Check if the time intervals overlap
        if (start_time2(j) <= end_time1(i)) && (end_time2(j) >= start_time1(i))
            % Add the intersecting row from access02 to the new table (as a cell array)
            intersected_data = [intersected_data; {start_time2(j), end_time2(j), duration2(j)}];
        end
    end
end

% Display the intersected data
disp(intersected_data);

% Save the intersected data to a new text file
fileID3 = fopen('access_intersected_a02.txt', 'w');
for k = 1:size(intersected_data, 1)
    fprintf(fileID3, '%s\t%s\t%f\n', datestr(intersected_data{k, 1}, 'dd mmm yyyy HH:MM:SS.FFF'), ...
        datestr(intersected_data{k, 2}, 'dd mmm yyyy HH:MM:SS.FFF'), intersected_data{k, 3});
end
fclose(fileID3);

%% For Access 2 intersected with Access 1
% Define file name
filename = 'access_intersected_a02.txt';

% Open the file and read the data
fid = fopen(filename, 'rt');

% Adjust the format specifier to properly parse fractional seconds and times
data = textscan(fid, '%d %s %d %d:%d:%f %d %s %d %d:%d:%f %f', 'Delimiter', ' ', 'MultipleDelimsAsOne', 1);
fclose(fid);

% Extract relevant data for start time
start_day = data{1};        % Start day
start_month = data{2};      % Start month (cell array of strings)
start_year = data{3};       % Start year
start_hour = data{4};       % Start hour
start_minute = data{5};     % Start minute
start_second = data{6};     % Start second

% Convert month names to month numbers
start_month_num = month(datetime(start_month, 'InputFormat', 'MMM'));

% Ensure all time components are integers
start_day = int32(start_day);
start_hour = int32(start_hour);
start_minute = int32(start_minute);
start_second = int32(start_second);

% Combine date and time for the start time using datetime
start_time = datetime(start_year, start_month_num, start_day, start_hour, start_minute, start_second);

% Extract relevant data for end time
end_day = data{7};          % End day
end_month = data{8};        % End month (cell array of strings)
end_year = data{9};         % End year
end_hour = data{10};        % End hour
end_minute = data{11};      % End minute
end_second = data{12};      % End second

% Convert month names to month numbers
end_month_num = month(datetime(end_month, 'InputFormat', 'MMM'));

% Ensure all time components are integers
end_day = int32(end_day);
end_hour = int32(end_hour);
end_minute = int32(end_minute);
end_second = int32(end_second);

% Combine date and time for the end time using datetime
end_time = datetime(end_year, end_month_num, end_day, end_hour, end_minute, end_second);

% Duration in seconds is already available
duration_seconds = data{13};

% Extract unique dates from start_time
unique_dates = unique(dateshift(start_time, 'start', 'day'));

% Pre-allocate for storing number of accesses and duration per day
num_accesses_per_day = zeros(length(unique_dates), 1);
duration_per_day = zeros(length(unique_dates), 1);

% Loop through each unique date
for i = 1:length(unique_dates)
    % Find indices of accesses on that date
    current_date = unique_dates(i);
    access_indices = find(dateshift(start_time, 'start', 'day') == current_date);
    
    % Store number of accesses for that date
    num_accesses_per_day(i) = length(access_indices);
    
    % Calculate the total duration for accesses on that date
    duration_per_day(i) = sum(duration_seconds(access_indices));
end

% Display the result
disp('Date          | Number of Accesses | Total Duration (seconds)');
disp('------------------------------------------------------------');
for i = 1:length(unique_dates)
    fprintf('%s | %d               | %.2f\n', datestr(unique_dates(i)), num_accesses_per_day(i), duration_per_day(i));
end

mean(duration_per_day)/mean(num_accesses_per_day)
std(duration_per_day)
std(duration_per_day)/mean(duration_per_day)

binEdges1 = 1300:30:2400;
% Create a histogram
histogram(duration_per_day, binEdges1);
% Add title and labels
title('Histogram of access duration per day');
xlabel('Value');
ylabel('Frequency');

binEdges2 = 1:1:7;
% Create a histogram
histogram(num_accesses_per_day, binEdges2);
% Add title and labels
title('Histogram of access number per day');
xlabel('Value');
ylabel('Frequency');

