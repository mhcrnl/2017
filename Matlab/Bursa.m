classdef Bursa
    %Afiseaza grafic ultimele 7 zile la bursa ale bancilor
   properties
      zile=[1:1:5];
      brd=[11.74 11.26 11.72 11.76 11.80];
      bcr = [132.0 135.0 134.5 134.0 133.0];
      transilvania =[];
      carpatica=[];
   end
   methods
       function grafic(obj)
          rbrd = fbrd(obj);
          rbcr = fbcr(obj);
          plot(obj.zile, rbrd,'r',obj.zile, rbcr, 'g' ), legend('brd','bcr') 
          %plot(obj.zile, obj.bcr, 'g')
       end
       function r = fbrd(obj)
          r = (obj.brd/11.74)*100;
          %disp(r)
       end
       function r = fbcr(obj)
          r = (obj.bcr/132.0)*100; 
       end
   end
end