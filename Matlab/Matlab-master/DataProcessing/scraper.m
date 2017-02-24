function [data] = scraper(path, data)
% The function scraper searches the entire folder structure behind the
% input folder for a folder that contains something interesting and
% and which isn't analysed yet. If such a folder is found, it is passed to
% analyse.m which analyses the containings of the folder and returns the
% obtained data. This data is returned by the scraper. 
%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% %%                                USAGE                               %%
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% You can use scrape with as argument the path to the root of the folder
% structure you want analysed. It is posible to pass the relative path. The
% function won't accept '/' as input argument since it would imply scanning
% your entire file system. 

%% Checking if user isn't a complete idiot
if path == filesep
    m=input('WTF dude?! scraping your entire file system? You sure?, Y/N [Y]:','s')
    if m == 'N'
        display('You chose wisely')
        return
    else
        error('You are an idiot, I will no longer obey!')
    end
end


%% Parsing path for analysation and retrieving data object
data = analyse(path, data)

%% Listing subfolders which might need to be analysed
listings = dir(path);
isub = [listings(:).isdir];
nameFolds = {listings(isub).name}';
nameFolds(ismember(nameFolds,{'.','..'})) = [];
if isempty(nameFolds)
    return
end

%% Recursively processing the subfolders.
for i = 1:length(nameFolds)
    sub = nameFolds(i);
    newPath = strcat(path, filesep, sub{1});
    data = scraper(newPath, data);
end
end