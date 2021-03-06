/* This file is part of simcoon.
 
 simcoon is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 simcoon is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with simcoon.  If not, see <http://www.gnu.org/licenses/>.
 
 */

///@file output.cpp
///@brief object that defines the output
///@version 1.0

#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <math.h>
#include <armadillo>
#include <simcoon/Simulation/Solver/output.hpp>

using namespace std;
using namespace arma;

namespace simcoon{

//=====Private methods for ellipsoid_characteristics===================================

//=====Public methods for ellipsoid_characteristics============================================

//@brief default constructor
//-------------------------------------------------------------
solver_output::solver_output()
//-------------------------------------------------------------
{
    o_nb_strain = 0;
    o_nb_stress = 0;
    o_nb_T = 0;
    o_nw_statev = 0;
    
    o_strain_type = 0;
    o_stress_type = 0;
    o_rotation_type = 0;
    o_tangent_modulus = 0;
}

/*!
 \brief Constructor with parameters
 \param nblock : number of blocks
 */

//-------------------------------------------------------------
solver_output::solver_output(const int &nblock)
//-------------------------------------------------------------
{
    o_nb_strain = 0;
    o_nb_stress = 0;
    o_nb_T = 0;
    o_nw_statev = 0;

    o_strain_type = 0;
    o_stress_type = 0;
    o_rotation_type = 0;
    o_tangent_modulus = 0;
    
    o_type.zeros(nblock);
    o_nfreq.zeros(nblock);
    o_tfreq.zeros(nblock);
}

/*!
 \brief Copy constructor
 \param so solver_output object to duplicate
 */

//------------------------------------------------------
solver_output::solver_output(const solver_output& so)
//------------------------------------------------------
{
    o_nb_strain = so.o_nb_strain;
    o_nb_stress = so.o_nb_stress;
    o_strain = so.o_strain;
    o_stress = so.o_stress;
    o_nb_T = so.o_nb_T;
    o_strain_type = so.o_strain_type;
    o_stress_type = so.o_stress_type;
    o_rotation_type = so.o_rotation_type;
    o_tangent_modulus = so.o_tangent_modulus;
    o_nw_statev = so.o_nw_statev;
	o_wanted_statev = so.o_wanted_statev;
	o_range_statev = so.o_range_statev;
    o_type = so.o_type;
    o_nfreq = so.o_nfreq;
    o_tfreq = so.o_tfreq;
}

/*!
 \brief destructor
 */

solver_output::~solver_output() {}

/*!
 \brief Standard operator = for solver_output objects
 */

//----------------------------------------------------------------------
solver_output& solver_output::operator = (const solver_output& so)
//----------------------------------------------------------------------
{
    o_nb_strain = so.o_nb_strain;
    o_nb_stress = so.o_nb_stress;
    o_strain = so.o_strain;
    o_stress = so.o_stress;
    o_nb_T = so.o_nb_T;
    o_strain_type = so.o_strain_type;
    o_stress_type = so.o_stress_type;
    o_rotation_type = so.o_rotation_type;
    o_tangent_modulus = so.o_tangent_modulus;
    o_nw_statev = so.o_nw_statev;
	o_wanted_statev = so.o_wanted_statev;
	o_range_statev = so.o_range_statev;
    o_type = so.o_type;
    o_nfreq = so.o_nfreq;
    o_tfreq = so.o_tfreq;
    
	return *this;
}

//--------------------------------------------------------------------------
ostream& operator << (ostream& s, const solver_output& so)
//--------------------------------------------------------------------------
{    
	s << "Display info on the output:\n ";
	s << "Number of strain/stress: " << so.o_nb_strain << "/" << so.o_nb_stress << "\t heat" << so.o_nb_T << " \n";
	s << "strain\n" << so.o_strain << "\n";
	s << "stress\n" << so.o_stress << "\n";
    
    /*std::map<string, int> list_strain_type;
    list_strain_type = {{"Green-Lagrange",0},{"Biot",1},{"Transformation gradient",2},{"logarithmic",3}};
    std::map<string, int> list_stress_type;
    list_stress_type = {{"Piola-Kirchoff II",0},{"Nominal Stress",1},{"Piola-Kirchoff II",2},{"Kirchoff",3},{"Cauchy",4}};*/

	s << "strain type\n" << so.o_strain_type << "\n";
	s << "stress type\n" << so.o_stress_type << "\n";
    s << "rotation type\n" << so.o_rotation_type << "\n";
    s << "tangent modulus type\n" << so.o_tangent_modulus << "\n";
    s << "statev:\n";
    s << "number wanted statev = " << so.o_nw_statev << "\n";
    s << "standalone statev\n" << so.o_wanted_statev << "\n";
    s << "range statev\n" << so.o_range_statev << "\n";
    
    s << "block\t type\t every\n";
    for (unsigned int i=0; i<so.o_type.n_elem; i++) {
        s << i+1 << "\t" << so.o_type(i) << "\t";
        if (so.o_type(i) == 1)
            s << so.o_nfreq(i);
        else if (so.o_type(i) ==2)
            s << so.o_tfreq(i);
        else
            s << "N/A";
        s << "\n\n";
        
    }
    
	return s;
}

} //namespace simcoon
