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

///@file read.hpp
///@brief To read from NsectionsX.dat
///@version 1.0

#pragma once
#include <string>
#include <armadillo>
#include <CGAL/Simple_cartesian.h>
#include <simcoon/Continuum_mechanics/Unit_cell/node.hpp>
#include <simcoon/Continuum_mechanics/Unit_cell/element.hpp>
#include <simcoon/Continuum_mechanics/Unit_cell/section_characteristics.hpp>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_3 Point;

namespace simcoon{
    
/// Function that splits a line using delimiters
std::vector<std::string> split(const std::string &, const char & = ',');
   
void unit_cell_essentials(unsigned int &, unsigned int &, unsigned int &, unsigned int &, const std::string & = "data", const std::string & = "unit_cell_essentials.inp");

/// Function that reads the characteristics of a phase
void read_sections(std::vector<section_characteristics> &, const unsigned int &, const std::string & = "data", const std::string & = "Nsections0.dat");

void read_abaqus_full_mesh(std::vector<section_characteristics> &, std::vector<Node> &, std::vector<Element> &, std::vector<std::vector<std::string> > &, const unsigned int &, const std::vector<std::string> &, const std::string & = "data", const std::string & = "Nsections.dat", const std::string & = "sc_mesh.dat", const std::string & = "mesh.inp");

void read_salome_full_mesh(std::vector<section_characteristics> &, std::vector<arma::Col<int> > &, const unsigned int &, const std::string & = "data", const std::string & = "Nsections.dat", const std::string & = "sc_mesh.dat", const std:: string & = "mesh.dat");

void read_salome_mesh(std::vector<Node> &, std::vector<Element> &, const std::string & = "data", const std:: string & = "mesh.dat");

void read_nodes_file(std::vector<Node> &, const std::string & = "data", const std::string & = "nodes0.inp");

void read_results(arma::vec &, arma::vec &, const std::string &, const std::string &);

void read_subphases_results(arma::vec &, arma::vec &, const unsigned int &, const std::string &, const std::string &);
    
} //namespace simcoon
