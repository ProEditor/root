// @(#)root/gl:$Id$
// Author:  Timur Pocheptsov  03/08/2004
// NOTE: This code moved from obsoleted TGLSceneObject.h / .cxx - see these
// attic files for previous CVS history

/*************************************************************************
 * Copyright (C) 1995-2006, Rene Brun and Fons Rademakers.               *
 * All rights reserved.                                                  *
 *                                                                       *
 * For the licensing terms see $ROOTSYS/LICENSE.                         *
 * For the list of contributors see $ROOTSYS/README/CREDITS.             *
 *************************************************************************/

#ifndef ROOT_TGLCylinder
#define ROOT_TGLCylinder

#ifndef ROOT_TGLLogicalShape
#include "TGLLogicalShape.h"
#endif

class TBuffer3DTube;

class TGLCylinder : public TGLLogicalShape 
{
private:
   Double_t fR1, fR2, fR3, fR4;
   Double_t fDz;
   Double_t fPhi1, fPhi2;

   TGLVector3 fLowPlaneNorm, fHighPlaneNorm;
   Bool_t fSegMesh;

protected:
   void DirectDraw(const TGLDrawFlags & flags) const;  

public:
   TGLCylinder(const TBuffer3DTube & buffer);
   ~TGLCylinder();

   // Cylinders support LOD (tesselation quality) adjustment along
   // X/Y axes (round the cylinder radius), but not along length (Z)
   virtual ELODAxes SupportedLODAxes() const { return ELODAxes(kLODAxesX | kLODAxesY); }

private:
   ClassDef(TGLCylinder,0) // a cylinderical logical shape
};

#endif

