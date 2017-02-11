<?php
   if( $_POST["location"] ) {
      $location = $_POST["location"];
      header( "Location:$location" );
      
      exit();
   }
?>
<html>
   <body>
   
      <p>Choose a site to visit :</p>
      
      <form action = "<?php $_SERVER['PHP_SELF'] ?>" method ="POST">
         <select name = "location">.
         
            <option value = "http://www.tutorialspoint.com">
               Tutorialspoint.com
            </option>
         
            <option value = "http://www.google.com">
               Google Search Page
            </option>
         
         </select>
         <input type = "submit" />
      </form>
      
   </body>
</html>