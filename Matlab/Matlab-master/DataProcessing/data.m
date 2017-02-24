classdef data < handle
    % The purpose of this object is to store data in which is obtained by
    % analyse.m
    
    properties
        % integers
        var1 = 10;
        var2 = 1;
        
        % array's
        arr1 = [2,3]
    end
    
    methods
        function obj = merge(obj, c1)
            % integers
            obj.var1 =  obj.var1 + c1.var1;
            obj.var2 =  obj.var2 + c1.var2;
            
            %arra's
            obj.arr1 = [obj.arr1,  c1.arr1];
        end
    end
end



