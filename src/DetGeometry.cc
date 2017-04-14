
#include <G4PhysicalConstants.hh>
#include "DetGeometry.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    material       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, material, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
   }

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
    return physWorld;
}


