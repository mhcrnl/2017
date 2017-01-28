/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package agendatelefonica;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;

/**
 *
 * @author mhcrnl
 */
public class ReadmeFile {
    
    public void scrieReadme(){
        String file = "README.md";
        String text ="## Synopsis\n" +
"\n" +
"At the top of the file there should be a short introduction and/ or overview that explains **what** the project is. This description should match descriptions added for package managers (Gemspec, package.json, etc.)\n" +
"\n" +
"## Code Example\n" +
"\n" +
"Show what the library does as concisely as possible, developers should be able to figure out **how** your project solves their problem by looking at the code example. Make sure the API you are showing off is obvious, and that your code is short and concise.\n" +
"\n" +
"## Motivation\n" +
"\n" +
"A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.\n" +
"\n" +
"## Installation\n" +
"\n" +
"Provide code examples and explanations of how to get the project.\n" +
"\n" +
"## API Reference\n" +
"\n" +
"Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.\n" +
"\n" +
"## Tests\n" +
"\n" +
"Describe and show how to run the tests with code examples.\n" +
"\n" +
"## Contributors\n" +
"\n" +
"Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.\n" +
"\n" +
"## License\n" +
"\n" +
"A short snippet describing the license (MIT, Apache, etc.)";
    
        try {
            File readme = new File(file);
            if(readme.exists()){
                System.out.println("Fila "+file+" este creata.");
                return;
            }
            FileOutputStream fis = new FileOutputStream(readme);
            OutputStreamWriter osw = new OutputStreamWriter(fis);
            Writer w = new BufferedWriter(osw);
            w.write(text);
            w.close();
        } catch(IOException e)  {
            System.err.println("Fila "+file+" nu a fost scrisa!");
        }
    }
}
