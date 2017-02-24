# XML-Parsing
Parsing XML file into struct in Matlab

node = xml_read(FILE_PATH)
return the root node of the XML file tree struct
<ui>
<li>if there are nodes with the same name connected to the same parent node, organize those children into Matlab cell array.</li>
<li>the value of leaf node is accessed by using CONTENT keyword</li>
</ui>
Example: node.history.observations.observation{1}.tempi.CONTENT
the above statement will return the temperature at the first hour on 06/25/2015
