//
//  ColorWorld.h
//  Jae Hyun Yoo
//  3/26/14.
//
//

#pragma once

#include <fstream>
#include "string.h"

#include "Map.h"
#include "LeapWrapper.h"
#include "CityDataStructures.h"

#include "OpenStreetMapProvider.h"
#include "GeoUtils.h"
#include "Utils.h"

#include "ofMain.h"
#include "ofxTween.h"
#include "ofxMSAPerlin.h"


class ColorWorld : public ofBaseApp
{
	public:
		void setup();
		void update();
		void draw();
        void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    private:
        double getMoveX( float );
        double getMoveY( float );
        double getMoveMouseX( );
        double getMoveMouseY( );
    
        // private method : gesture debug purpose
        void gestureDebug();
    
        // custom 3d noise
        ofVec3f noise3d( ofVec3f, int);
    
    
    //Member Variables-------------------------------------
    
        // Leap Object
        ofxLeapMotion   m_leapObj;
        ofPoint         m_leapPalmPos;
        vector <ofxLeapMotionSimpleHand> m_leapHands;

        // Modest Map object
        Map             m_map;
    
        // Google MapView ofImages
        ofImage         m_gMapView;
        ofImage         m_gStreetView;
    
        // Location informations
        double          m_longitude;
        double          m_latitude;
        string          m_str_latitude;
        string          m_str_longitude;
        string          m_cityName;
        int             m_cityId;
        vector<City>    m_cityLocations;
    
        // Map Data
        vector<ofPoint>     m_coordinates;
        map<string,ofColor> m_colorData;
        map<string,GeoData> m_streetData;
        map<string,float>   m_elevationData;
        map<string,ofImage> m_imageData;
    
        vector<ofPoint> m_onMapPos;
        vector<ofPoint> m_onMapClr;
    
        // Music Object
        ofSoundPlayer   m_bgm;
        ofSoundPlayer   m_sfx;
        int   m_timeFrame;
        float m_musicSpeed;
        float m_musicClr;
        float m_musicClrRemapped;
    
        // Draw informations
        vector< vector<ofColor> > m_streetPalettes;
        deque< deque<ofColor> > m_colors;
        deque< deque<ofPoint> > m_points;
        deque<float> m_remappedHeight;
    
        // Switches
        bool m_enabledLeap;
        bool m_enabledClrSearch;
        bool m_enabledInternet;
        bool m_enabledClrCache;
        bool m_enabledMusicVisualization;
        bool m_enabledReset;
    
        // elapsedTime
        float m_elapsedTime;
    
        // utils
        float clamp;
        ofColor                 m_tmpPalette;
        ofxEasingQuad           easeQuad;
        ofxTween::ofxEasingType easingType;
};
