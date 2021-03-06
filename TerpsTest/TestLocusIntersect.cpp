/** \file TestLocusIntersect.cpp
*   \brief
*/

/****************************************************************************/
/*  TestLocusIntersect.cpp                                                  */
/****************************************************************************/
/*                                                                          */
/*  Copyright 2008 - 2016 Paul Kohut                                        */
/*  Licensed under the Apache License, Version 2.0 (the "License"); you may */
/*  not use this file except in compliance with the License. You may obtain */
/*  a copy of the License at                                                */
/*                                                                          */
/*  http://www.apache.org/licenses/LICENSE-2.0                              */
/*                                                                          */
/*  Unless required by applicable law or agreed to in writing, software     */
/*  distributed under the License is distributed on an "AS IS" BASIS,       */
/*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or         */
/*  implied. See the License for the specific language governing            */
/*  permissions and limitations under the License.                          */
/*                                                                          */
/****************************************************************************/

//#include "stdafx.h"
#include <string>
#include <fstream>
#include "LatLongConversions.h"
#include "Conversions.h"
#include "GeoFormulas.h"
#include <regex>


using namespace GeoCalcs;
using namespace std;

bool ParseLocusIntersect3(string sLine3, string &sIntersection1Lat, string &sIntersection1Lon)
{
    bool bPassed = false;
    trim(sLine3);
    try
    {
        regex_constants::syntax_option_type flags = regex_constants::icase | regex_constants::ECMAScript;

        string sRxPat = "[,][A-z]+[,]";
        sRxPat += "([N/A]+|[0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([N/A]+|[0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";


        regex pat(sRxPat, flags);
        int const sub_matches[] = {1, 2,};
        sregex_token_iterator it(sLine3.begin(), sLine3.end(), pat, sub_matches);
        sregex_token_iterator s_end;
        if (it != s_end)
        {
            sIntersection1Lat = *it++;
            sIntersection1Lon = *it++;
            bPassed = true;
        }
    }
    catch (regex_error &e)
    {
        cout << "\n" << e.what();
        return false;
    }
    return bPassed;

}

bool ParseLocusIntersect1(string sLine1, string &sTestId, string &sGeoStartLat, string &sGeoStartLon,
                          string &sGeoEndLat, string &sGeoEndLon,
                          string &sLocusStartLat, string &sLocusStartLon, string &sLocusEndLat, string &sLocusEndLon,
                          string &sLocusStartDist, string &sLocusEndDist)
{
    bool bPassed = false;
    trim(sLine1);
    try
    {
        regex_constants::syntax_option_type flags = regex_constants::icase | regex_constants::ECMAScript;

        string sRxPat = "([a-zA-Z]*\\d*)[,]";
        sRxPat += "[0-9A-z ]+[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([-+]?[0-9]*[.]?[0-9]+)[,]([-+]?[0-9]*[.]?[0-9]+)";

        regex pat(sRxPat, flags);
        int const sub_matches[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
        sregex_token_iterator it(sLine1.begin(), sLine1.end(), pat, sub_matches);
        sregex_token_iterator s_end;
        if (it != s_end)
        {
            sTestId = *it++;
            sGeoStartLat = *it++;
            sGeoStartLon = *it++;
            sGeoEndLat = *it++;
            sGeoEndLon = *it++;
            sLocusStartLat = *it++;
            sLocusStartLon = *it++;
            sLocusEndLat = *it++;
            sLocusEndLon = *it++;
            sLocusStartDist = *it++;
            sLocusEndDist = *it++;
            bPassed = true;
        }
    }
    catch (regex_error &e)
    {
        cout << "\n" << e.what();
        return false;
    }
    return bPassed;
}

bool ParseLocusIntersect2(string sLine2, string &sGeoStartLat, string &sGeoStartLon,
                          string &sGeoEndLat, string &sGeoEndLon,
                          string &sLocusStartLat, string &sLocusStartLon, string &sLocusEndLat, string &sLocusEndLon,
                          string &sLocusStartDist, string &sLocusEndDist)
{
    bool bPassed = false;
    trim(sLine2);

    try
    {
        regex_constants::syntax_option_type flags = regex_constants::icase | regex_constants::ECMAScript;

        string sRxPat = "[,][0-9A-z ]+[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[NS])[,]([0-9]*[:][0-9]*[:][0-9]*[.][0-9]*[WE])[,]";
        sRxPat += "([-+]?[0-9]*[.]?[0-9]+)[,]([-+]?[0-9]*[.]?[0-9]+)";

        regex pat(sRxPat, flags);
        int const sub_matches[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,};
        sregex_token_iterator it(sLine2.begin(), sLine2.end(), pat, sub_matches);
        sregex_token_iterator s_end;
        if (it != s_end)
        {
            sGeoStartLat = *it++;
            sGeoStartLon = *it++;
            sGeoEndLat = *it++;
            sGeoEndLon = *it++;
            sLocusStartLat = *it++;
            sLocusStartLon = *it++;
            sLocusEndLat = *it++;
            sLocusEndLon = *it++;
            sLocusStartDist = *it++;
            sLocusEndDist = *it++;
            bPassed = true;
        }
    }
    catch (regex_error &e)
    {
        cout << "\n" << e.what();
        return false;
    }

    return bPassed;
}

bool ParseLocusIntersect(string sLine1, string sLine2, string sLine3)
{
    bool bPassed = true;

    string sLocus1GeoStartLat, sLocus1GeoStartLong, sLocus1GeoEndLat, sLocus1GeoEndLong;
    string sLocus1StartLat, sLocus1StartLong, sLocus1EndLat, sLocus1EndLong;
    string sLocus1StartDist, sLocus1EndDist;

    string sLocus2GeoStartLat, sLocus2GeoStartLong, sLocus2GeoEndLat, sLocus2GeoEndLong;
    string sLocus2StartLat, sLocus2StartLong, sLocus2EndLat, sLocus2EndLong;
    string sLocus2StartDist, sLocus2EndDist;

    string sIntersection1Lat, sIntersection1Long;
    string sTestId;

    if (!ParseLocusIntersect1(sLine1, sTestId, sLocus1GeoStartLat, sLocus1GeoStartLong, sLocus1GeoEndLat,
                              sLocus1GeoEndLong,
                              sLocus1StartLat, sLocus1StartLong, sLocus1EndLat, sLocus1EndLong, sLocus1StartDist,
                              sLocus1EndDist))
        return false;

    if (!ParseLocusIntersect2(sLine2, sLocus2GeoStartLat, sLocus2GeoStartLong, sLocus2GeoEndLat, sLocus2GeoEndLong,
                              sLocus2StartLat, sLocus2StartLong, sLocus2EndLat, sLocus2EndLong, sLocus2StartDist,
                              sLocus2EndDist))
        return false;

    if (!ParseLocusIntersect3(sLine3, sIntersection1Lat, sIntersection1Long))
        return false;

    Locus locus1, locus2;
    locus1.geoStart.Set(Deg2Rad(ParseLatitude(sLocus1GeoStartLat)), Deg2Rad(ParseLongitude(sLocus1GeoStartLong)));
    locus1.geoEnd.Set(Deg2Rad(ParseLatitude(sLocus1GeoEndLat)), Deg2Rad(ParseLongitude(sLocus1GeoEndLong)));
    locus1.locusStart.Set(Deg2Rad(ParseLatitude(sLocus1StartLat)), Deg2Rad(ParseLongitude(sLocus1StartLong)));
    locus1.locusEnd.Set(Deg2Rad(ParseLatitude(sLocus1EndLat)), Deg2Rad(ParseLongitude(sLocus1EndLong)));
    locus1.startDist = NmToMeters(atof(sLocus1StartDist.c_str()));
    locus1.endDist = NmToMeters(atof(sLocus1EndDist.c_str()));
    locus1.lineType = 0;

    locus2.geoStart.Set(Deg2Rad(ParseLatitude(sLocus2GeoStartLat)), Deg2Rad(ParseLongitude(sLocus2GeoStartLong)));
    locus2.geoEnd.Set(Deg2Rad(ParseLatitude(sLocus2GeoEndLat)), Deg2Rad(ParseLongitude(sLocus2GeoEndLong)));
    locus2.locusStart.Set(Deg2Rad(ParseLatitude(sLocus2StartLat)), Deg2Rad(ParseLongitude(sLocus2StartLong)));
    locus2.locusEnd.Set(Deg2Rad(ParseLatitude(sLocus2EndLat)), Deg2Rad(ParseLongitude(sLocus2EndLong)));
    locus2.startDist = NmToMeters(atof(sLocus2StartDist.c_str()));
    locus2.endDist = NmToMeters(atof(sLocus2EndDist.c_str()));
    locus2.lineType = 0;

    LLPoint intersection;

    int nVal = LocusIntersect(locus1, locus2, intersection, kTol, kEps);

    if (nVal == 0)
    {
        if (sIntersection1Lat.compare("N/A") != 0)
        {
            string sPtIntLat = ConvertLatitudeDdToDms(Rad2Deg(intersection.latitude));
            string sPtIntLon = ConvertLongitudeDdToDms(Rad2Deg(intersection.longitude));
            cout << "\n" << sTestId << "failed: Expected solution of: " << sIntersection1Lat << " " <<
            sIntersection1Long << " but none was found";
            bPassed = false;
        }
    }
    else
    {
        string sPtIntLat = ConvertLatitudeDdToDms(Rad2Deg(intersection.latitude));
        string sPtIntLon = ConvertLongitudeDdToDms(Rad2Deg(intersection.longitude));
        if (sPtIntLat.compare(sIntersection1Lat) != 0)
        {
            double dLat = Deg2Rad(ParseLatitude(sIntersection1Lat));
            if (IsApprox(dLat, intersection.latitude, 1e-10))
                cout << "\n" << sTestId << " within rounding tolerance of 1e-10: Intersect 1 Latitude: " <<
                sIntersection1Lat << " calced: " << sPtIntLat;
            else
            {
                cout << "\n" << sTestId << " failed: Expected Intersect 1 latitude: " << sIntersection1Lat <<
                "  calced: " << sPtIntLat;
                bPassed = false;
            }
        }
        if (sPtIntLon.compare(sIntersection1Long) != 0)
        {
            double dLon = Deg2Rad(ParseLongitude(sIntersection1Long));
            if (IsApprox(dLon, intersection.longitude, 1e-10))
                cout << "\n" << sTestId << " within rounding tolerance of 1e-10: Intersect 1 Longitude: " <<
                sIntersection1Long << " calced: " << sPtIntLon;
            else
            {
                cout << "\n" << sTestId << " failed: Expected Intersect 1 longitude: " << sIntersection1Long <<
                "  calced: " << sPtIntLon;
                bPassed = false;
            }
        }
    }
    return bPassed;
}


int TestLocusIntersect(const string &sFilePath)
{
    ifstream infile;
    infile.exceptions(ifstream::eofbit | ifstream::failbit | ifstream::badbit);
    int nCount = 0;
    int nCommentCount = 0;
    bool bPassed = true;
    try
    {
        string sLine1, sLine2, sLine3;
        infile.open(sFilePath.c_str(), ifstream::in);

        while (!infile.eof())
        {
            getline(infile, sLine1);
            if (sLine1.at(0) == '#')
            {
                nCommentCount++;
            }
            else
            {
                getline(infile, sLine2);
                getline(infile, sLine3);
                if (!ParseLocusIntersect(sLine1, sLine2, sLine3))
                    bPassed = false;
                nCount++;
            }
        }
        infile.close();
        return bPassed;
    }

    catch (ifstream::failure e)
    {
        int nError = -99;
        // Per C++ standards for ifstream::failbit with global function getline
        // No characters were extracted because the end was prematurely found.Notice
        // that some eofbit cases will also set failbit.
        // In this case the end of the file is read and causes both flags to be raised,
        // so this presumably means all the data has been read correctly.
        if ((infile.rdstate() & ifstream::failbit) && (infile.rdstate() & ifstream::eofbit) != 0)
            nError = bPassed;
        else if ((infile.rdstate() & ifstream::failbit) != 0)
            nError = -1;
        else if ((infile.rdstate() & ifstream::badbit) != 0)
            nError = -2;
        else if ((infile.rdstate() & ifstream::eofbit) != 0)
            nError = -3;
        if (infile.is_open())
            infile.close();
        return nError;
    }
}
