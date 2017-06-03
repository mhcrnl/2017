#!/usr/bin/ruby -w

class Save
    #...................................................
    # Constructor
    def initialize( filename, mode)
        @filename = filename
        @mode = mode
        #@obj = obj
    end
    #....................................................
    # Metoda salveaza datele intr-o fila
    def save_to_file(obj)
        File.open(@filename, @mode) do |aFile|
            aFile.puts "#{obj}"
        end
    end
    def read_from_file
        File.open(@filename, @mode = "r") do |rFile|
            rFile.gets
        end
    end
    def read_from_file_1
        rFile = File.new(@filename, @mode = "r")
        if rFile
            continut = rFile.sysread(2000)
            puts continut
        else
            "Fila nu a fost deschisa!"
        end
    end
end
