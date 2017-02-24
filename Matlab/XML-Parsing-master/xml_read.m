function [ rootNode ] = xml_read( filePath )
%XML_READ constructs tree structure from xml file
% Created by Tianshu Wei
% 01/13/2016
    try
        dom = xmlread(filePath);
    catch
        error('Failed to read XML file %s.',filePath);
    end
    if ~dom.getChildNodes.getLength
        rootNode = struct();
    else
        % Parse xml file
        try
            eval(strcat(char(dom.getChildNodes.item(0).getNodeName),...
                '=parseChildNodes(dom.getChildNodes.item(0))'));
            eval(strcat('rootNode=',char(dom.getChildNodes.item(0).getNodeName),';'));
        catch
           error('Unable to parse XML file %s.',filePath);
        end
    end
end

function children = parseChildNodes(theNode)
    children = struct();
    % Construct the tree in recursive fashion
    if theNode.hasChildNodes
       childNodes = theNode.getChildNodes;
       numChildNodes = childNodes.getLength;
       % Add children in DFS fashion
       for count = 1:1:numChildNodes
           theChild = childNodes.item(count-1);
           childName = theChild.getNodeName;
           %disp([char(childName),num2str(numChildNodes)]);
           if ~strcmp(childName,'#text') || numChildNodes==1 % Not empty entry
               % Duplicated node
               if any(strcmp(fieldnames(children),childName)) 
                   childLen = eval( strcat( 'length(children.',char(childName),')' ) );
                   eval(strcat('children.',char(childName),...
                       '{',num2str(childLen+1),'}=','parseChildNodes(theChild);'));
               else
                   % Leaf node
                   pos = findstr(childName, '#'); % some leaf node that is not marked as #text, 04/16/2016
                   if strcmp(childName,'#text') || length(pos)>0
                       eval(strcat('children.','CONTENT','=''',char(theChild.getData),''';'));
                   % Intermediate node
                   else    
                       % First time assignment of duplicated node
                       if(count<numChildNodes && distinct(childNodes,count+1,childName)) %strcmp(childNodes.item(count+1).getNodeName,childName)
                           eval(strcat('children.',char(childName),'{1}=','parseChildNodes(theChild);'));
                       % Distinct node
                       else 
                           eval(strcat('children.',char(childName),'=','parseChildNodes(theChild);'));
                       end
                   end
               end
           end
       end
    end
    % It is not value node i.e., proporty node
    if ~any(strcmp(theNode.methods,'getData'))
        theAttributes = theNode.getAttributes;
        numAttributes = theAttributes.getLength;
        for count = 1:1:numAttributes
            theAttri = theAttributes.item(count-1);
            eval(strcat('children.Attributes.',...
                char(theAttri.getName),'=''',char(theAttri.getValue),''';'));
        end
    end
end

% Check whether current child node is distinct 
function multiple = distinct(obj,index,name)
    multiple = 0;
    length = obj.getLength;
    for i=index:1:length
        if strcmp(obj.item(i-1).getNodeName,name)
            multiple = 1;
            return;
        end
    end
end
