#include <Stdlib.h>
#include <String.h>


double VA = 0.0;
double IA = 0.0;
double PA = 0.0;

double PApre = 0.0;
double VApre = 0.0;

double VAprev = 0.0;
double IAprev = 0.0;
double VOprev = 0.0;
double OCprev = 0.0;
double PAprev = 0.0;
double Vbatprev = 0.0;

double VO = 0.0;
double OC = 0.0;

double Vbat = 0.0;
double Vbatmax = 28.0;


double IOmax = 30;
double VOmax = 325.0;

double PPWM = 0.00;

double D = 0.3;
double step = 0.003;
double Dmax =0.6;
double Dmin = 0.2;

double a = 0.0;
double b = 0.0;
double c = 0.0;


/////////////////////////////////////////////////////////////////////
// FUNCTION: SimulationStep
//   This function runs at every time step.
//double t: (read only) time
//double delt: (read only) time step as in Simulation control
//double *in: (read only) zero based array of input values. in[0] is the first node, in[1] second input...
//double *out: (write only) zero based array of output values. out[0] is the first node, out[1] second output...
//int *pnError: (write only)  assign  *pnError = 1;  if there is an error and set the error message in szErrorMsg
//    strcpy(szErrorMsg, "Error message here..."); 
// DO NOT CHANGE THE NAME OR PARAMETERS OF THIS FUNCTION
void SimulationStep(
		double t, double delt, double *in, double *out,
		 int *pnError, char * szErrorMsg,
		 void ** reserved_UserData, int reserved_ThreadIndex, void * reserved_AppPtr) 
{ 
VA = in[0];
if(VA < 0) { VA = 0; }
VA = (VA + VAprev) / 2;

IA = in[1];
if(IA < 0) { IA = 0; }
IA = (IA + IAprev) / 2;

PA = VA * IA;

VO = in[2];
if(VO < 0) { VO = 0; }
VO = (VO + VOprev) / 2;

if(VO > 0){
OC = PA / VO;
}
if(OC < 0) { OC = 0; }
OC = (OC + OCprev) / 2;

Vbat = in[4];
if(Vbat < 0) { Vbat = 0; }
Vbat = (Vbat + Vbatprev) / 2;

if(Vbat > Vbatmax) { out[3] = 1; }
else if(Vbat < Vbatmax) { out[3] = 0; }

if(VO > 450) {
 out[1] = 1;
 a = 1;
}

if(VO >350 && c == 1){ out[2] = 1; }

if(VA > 250 && a == 1){
 b = 1;
}

if(a == 1){

if(OC > IOmax) {
    D = D - step;
}

else if (VO > VOmax){
   D = D - step;
}

else
{

    if(PA > PApre && VA > VApre)          {D = D - step;}
    else if(PA > PApre && VA < VApre)   {D = D + step;}
    else if(PA < PApre && VA > VApre)   {D = D + step;}
    else if(PA < PApre && VA < VApre)   {D = D - step;}
    else if(VO < VOmax)                           {D = D + step;}

   VApre = VA;
   PApre = PA;

}

}
  

if(b == 1) {

VO = in[2];
if(VO < 0) { VO = 0; }
VO = (VO + VOprev) / 2;

if(VO > 320) { c = 1; }

}




if(D > Dmax){
D = Dmax;
}

else if(D < Dmin){
D = Dmin;
}

    VAprev = VA;
    IAprev = IA;
    VOprev = VO;
    OCprev = OC;
    Vbatprev = Vbat;

  out[0] = D;


 
} 



/////////////////////////////////////////////////////////////////////
// FUNCTION: SimulationBegin
//   Initialization function. This function runs once at the beginning of simulation
//   For parameter sweep or AC sweep simulation, this function runs at the beginning of each simulation cycle.
//   Use this function to initialize static or global variables.
//const char *szId: (read only) Name of the C-block 
//int nInputCount: (read only) Number of input nodes
//int nOutputCount: (read only) Number of output nodes
//int nParameterCount: (read only) Number of parameters is always zero for C-Blocks.  Ignore nParameterCount and pszParameters
//int *pnError: (write only)  assign  *pnError = 1;  if there is an error and set the error message in szErrorMsg
//    strcpy(szErrorMsg, "Error message here..."); 
// DO NOT CHANGE THE NAME OR PARAMETERS OF THIS FUNCTION
void SimulationBegin(
		const char *szId, int nInputCount, int nOutputCount,
		 int nParameterCount, const char ** pszParameters,
		 int *pnError, char * szErrorMsg,
		 void ** reserved_UserData, int reserved_ThreadIndex, void * reserved_AppPtr) 
{ 

  
} 



/////////////////////////////////////////////////////////////////////
// FUNCTION: SimulationEnd
//   Termination function. This function runs once at the end of simulation
//   For parameter sweep or AC sweep simulation, this function runs at the end of each simulation cycle.
//   Use this function to de-allocate any allocated memory or to save the result of simulation in an alternate file.
// Ignore all parameters for C-block 
// DO NOT CHANGE THE NAME OR PARAMETERS OF THIS FUNCTION
void SimulationEnd(const char *szId, void ** reserved_UserData, int reserved_ThreadIndex, void * reserved_AppPtr) 
{ 
 
} 



