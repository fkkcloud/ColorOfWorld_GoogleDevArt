//
//  Utils
//  Jae Hyun Yoo
//  3/26/14.
//
//
//  Utility functions


// Util & Config functions
namespace Utils {
    
    void loadColors( std::map<string,GeoData> &streetData, vector<ofPoint> &coordinates,
                    std::string filename )
    {
        ofBuffer file = ofBufferFromFile( filename );
    
        // Loop through text lines
        while ( !file.isLastLine() )
        {
            vector <string> values = ofSplitString(file.getNextLine(), ",");
        
            float lat = ofToFloat(values[0]);
            float lon = ofToFloat(values[1]);
        
            coordinates.push_back( ofPoint(lat, lon) );

            std::string str = ofToString(lat) + "," + ofToString(lon);

            GeoData geoData = {values[2], values[3]};
            streetData[str] = geoData;
        }
    }

    void loadImages( std::map<std::string,ofColor> &colorData, std::map<std::string,ofImage> &imageData,
                std::string filename )
    {
        ofBuffer file = ofBufferFromFile( filename );
    
        // Loop through text lines

        while ( !file.isLastLine() )
        {
            vector<std::string> values = ofSplitString(file.getNextLine(), ",");
            
            float lat = ofToFloat(values[0]);
            float lon = ofToFloat(values[1]);
            
            std::string imagePath = "streetViewMap_"
            + values[0]
            + "_"
            + values[1];
        
            std::string str = ofToString(lat) + "," + ofToString(lon);
            
            colorData[str] = ofImage(imagePath).getColor(65, 65);
            imageData[str] = ofImage(imagePath);
        }
    }
    
    void loadElevations( std::map<std::string,float> &elevationData, std::string filename )
    {
        ofBuffer file2 = ofBufferFromFile(filename);
        while ( !file2.isLastLine() )
        {
            vector <string> values = ofSplitString(file2.getNextLine(), ",");
            
            float lat = ofToFloat(values[0]);
            float lon = ofToFloat(values[1]);
            
            string str = ofToString(lat) + "," + ofToString(lon);
            
            elevationData[str] = ofToFloat(values[2]);
        }
    }
    
    void citySetup( vector<City> cityLocations )
    {
        // have to add more cities
        City seoul          = { 37.5833 ,   127.05   , "Seoul",         0 };
        City shanghai       = { 31.233  ,   121.45   , "Shanghai",      1 };
        City tokyo          = { 35.6833 ,   139.7333 , "Tokyo",         2 };
        City lasvegas       = { 14.86667,   -88.06667, "Las Vegas",     3 };
        City sanfrancisco   = { 37.77493,  -122.41942, "San Francisco", 4 };
    
        cityLocations.push_back( seoul        );      // Seoul
        cityLocations.push_back( shanghai     );      // Shanghai
        cityLocations.push_back( tokyo        );      // Tokyo
        cityLocations.push_back( lasvegas     );      // Las Vegas
        cityLocations.push_back( sanfrancisco );      // San Francisco
    }
    
    void setMusic( ofSoundPlayer &soundObj, std::string musicName )
    {
        soundObj.loadSound(musicName);
        soundObj.play();
        soundObj.setLoop(true);
    }

    
} // End of Utils



