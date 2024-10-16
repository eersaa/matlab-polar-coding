% PENCODE_CORE_CODEGEN   Generate static library pencode_core from pencode_core.
% 
% Script generated from project 'pencode_core.prj' on 16-Oct-2024.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config('lib','ecoder',true);
cfg.TargetLang = 'C++';
cfg.GenerateReport = true;
cfg.MaxIdLength = 1024;
cfg.ReportPotentialDifferences = false;

%% Define argument types for entry-point 'pencode_core'.
ARGS = cell(1,1);
ARGS{1} = cell(2,1);
ARGS{1}{1} = coder.typeof(0,[128  1]);
ARGS{1}{2} = coder.typeof(0);

%% Invoke MATLAB Coder.
codegen -config cfg pencode_core -args ARGS{1}

