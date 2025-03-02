function varargout = zijing(varargin)
% ZIJING MATLAB code for zijing.fig
%      ZIJING, by itself, creates a new ZIJING or raises the existing
%      singleton*.
%
%      H = ZIJING returns the handle to a new ZIJING or the handle to
%      the existing singleton*.
%
%      ZIJING('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in ZIJING.M with the given input arguments.
%
%      ZIJING('Property','Value',...) creates a new ZIJING or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before zijing_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to zijing_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help zijing

% Last Modified by GUIDE v2.5 18-Dec-2024 10:20:00

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @zijing_OpeningFcn, ...
                   'gui_OutputFcn',  @zijing_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before zijing is made visible.
function zijing_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to zijing (see VARARGIN)

% Choose default command line output for zijing
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes zijing wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = zijing_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --------------------------------------------------------------------
function open_Callback(hObject, eventdata, handles)
% hObject    handle to open (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function open_pic_Callback(hObject, eventdata, handles)
global img;
filename='C:\Users\Administrator\Desktop\color.jpg';
img=imread(filename);
subplot(2,2,1);
imshow(img);
title('original picture');


% --------------------------------------------------------------------
function open_file_Callback(hObject, eventdata, handles)
global img;
[filename,pathname]=uigetfile({'*.bmp;*.jpg;*.gif;*.emg','files';},'Open a file');  
datafile=[pathname,filename];  
img=imread(datafile);
subplot(2,3,1);
imshow(img);
title('original picture');


% --------------------------------------------------------------------
function tools_Callback(hObject, eventdata, handles)
% hObject    handle to tools (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function color2gray_Callback(hObject, eventdata, handles)
global img;
global img_gray;
img_gray=rgb2gray(img);
subplot(2,2,2);
imshow(img_gray);
title('gray picture');

% --------------------------------------------------------------------
function img2bw_Callback(hObject, eventdata, handles)
global img;
n=0.5;
global BW;
BW=im2bw(img,n); 
subplot(2,2,3);
imshow(BW);
title('bw picture: 0.5');


% --------------------------------------------------------------------
function rgb2hsv_Callback(hObject, eventdata, handles)
global img;
global img_hsv;
img_hsv=rgb2hsv(img);
subplot(2,2,4);
imshow(img_hsv);
title('hsv picture');


% --------------------------------------------------------------------
function save_Callback(hObject, eventdata, handles)
% hObject    handle to save (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function save_gray_Callback(hObject, eventdata, handles)
global img_gray;
[filename, pathname] = uiputfile('*.jpg;','JPG files', 'gray picture'); 
if isequal(filename,0) || isequal(pathname,0)    
    return; 
else
    fpath=fullfile(pathname, filename); 
end
    imwrite(img_gray,fpath,'jpg');


% --------------------------------------------------------------------
function save_bw_Callback(hObject, eventdata, handles)
global BW;
[filename, pathname] = uiputfile('*.jpg;','JPG files', 'bw picture'); 
if isequal(filename,0) || isequal(pathname,0)    
    return; 
else
    fpath=fullfile(pathname, filename); 
end
    imwrite(BW,fpath,'jpg');

% --------------------------------------------------------------------
function save_hsv_Callback(hObject, eventdata, handles)
global img_hsv;
[filename, pathname] = uiputfile('*.jpg;','JPG files', 'hsv picture'); 
if isequal(filename,0) || isequal(pathname,0)    
    return; 
else
    fpath=fullfile(pathname, filename); 
end
    imwrite(img_hsv,fpath,'jpg');


% --------------------------------------------------------------------
function operate_Callback(hObject, eventdata, handles)
% hObject    handle to operate (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function geometry_Callback(hObject, eventdata, handles)
% hObject    handle to geometry (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function img_resize_Callback(hObject, eventdata, handles)
global img;
I1=imresize(img,0.5,'nearest'); 
figure;imshow(I1)
title('resize picture_nearest_0.5');

I2=imresize(img,1.5,'bilinear');
figure;
imshow(I2);
title('resize picture_bilinear_1.5');

I3=imresize(img,1.5,'bicubic');
figure;imshow(I3);
title('resize picture_bicubic_2');


% --------------------------------------------------------------------
function img_rotate_Callback(hObject, eventdata, handles)
global img;
I1=imrotate(img,30,'nearest');
figure;imshow(I1);
title('rotate picture_30');


% --------------------------------------------------------------------
function inverse_Callback(hObject, eventdata, handles)
global img;
img1=255-img;
I=imcomplement(img);
figure;imshow(I);
figure;imshow(img1);

% --------------------------------------------------------------------
function img_flip_Callback(hObject, eventdata, handles)
global img;
I1=flip(img,1);
figure;imshow(I1);
title('Vertical');
I2=flip(img,2);
figure;imshow(I2);
title('Horizontal');


% --------------------------------------------------------------------
function algebra_Callback(hObject, eventdata, handles)
% hObject    handle to algebra (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function img_add_Callback(hObject, eventdata, handles)
global img;
global J1;
global J2;
global J3;
global J4;
global J5;
J_final=img;
a=[J1,J2,J3,J4,J5];
for i=1:length(a)
    J_final=uint16(J_final)+uint16(a(i));
end
J_final=J_final/(length(a)+1);
figure;imshow(uint8(J_final));
title('img_add');


% --------------------------------------------------------------------
function img_noise_Callback(hObject, eventdata, handles)
global img;
global J1;
global J2;
global J3;
global J4;
global J5;
img_double=im2double(img);
var_local=0.02*ones(size(img_double));
J1=imnoise(img, 'salt & pepper', 0.02);
J2=imnoise(img, 'gaussian', 0.02); 
J3=imnoise(img_double,'poisson'); 
J4=imnoise(img, 'localvar', var_local); 
J5=imnoise(img, 'speckle', 0.02);
figure;imshow(J1);
title('salt&pepper');



% --------------------------------------------------------------------
function img_substract_Callback(hObject, eventdata, handles)
global img;
global J1;
global J2;
global J3;
global J4;
global J5;
J6=imsubtract(J1,J2);
figure;imshow(J6);
title('img_substract');


% --------------------------------------------------------------------
function fourier_transform_Callback(hObject, eventdata, handles)
% hObject    handle to fourier_transform (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function generate_Callback(hObject, eventdata, handles)
global A;
A=zeros(64,64);
A(38:90,58:70)=255;
A(44:84,44:84)=255;
subplot(3,3,1);
imshow(A);
title('generate');


% --------------------------------------------------------------------
function image_spectrum_Callback(hObject, eventdata, handles)
global A;
f=fft2(A);
subplot(3,3,2);
imshow(log(1+abs(f)),[]);
title('fourier');
fc=fftshift(f);
subplot(3,3,3);
imshow(abs(fc),[]);
title('centralization');
subplot(3,3,4);
imshow(log(1+abs(fc)),[ ]);
title('log_enhance');


% --------------------------------------------------------------------
function show_3D_Callback(hObject, eventdata, handles)
global A;
f=fft2(A); 
f=fftshift(f); 
f=abs(f); 
n=64; 
x=1:n;
y=1:n; 
subplot(3,3,5);
mesh(x,y,f(x,y));
title('3D Surface Plot'); 



% --------------------------------------------------------------------
function translational_property_Callback(hObject, eventdata, handles)
global A;
%t_row=20;
%t_col=25; 
%B =circshift(A,[t_row, t_col]);  
B=zeros(64,64);
B(68:120,98:110)=255;
f2=fft2(B);  
%f2=fftshift(f2);
f2=abs(f2);
subplot(3,3,6);  
imshow(B,[]);  
title('Translated Image B');  
subplot(3,3,7);  
imshow(log(1+f2), []); 
title('Spectrum of B');


% --------------------------------------------------------------------
function rotatability_Callback(hObject, eventdata, handles)
global A;
angle=90;
C=imrotate(A, angle, 'crop'); 
%C=zeros(64,64);
%C(58:70,38:90)=255;
f2=fft2(C);  
%f2=fftshift(f2);
f2=abs(f2); 
subplot(3,3,8);  
imshow(C,[]);  
title('Rotated Image C');  
subplot(3,3,9);  
imshow(log(1 + f2),[]);
title('Spectrum of C');  


% --------------------------------------------------------------------
function test_Callback(hObject, eventdata, handles)
filename='C:\Users\Administrator\Desktop\color.jpg';
img=imread(filename);
if size(img,3)==3  
    img=rgb2gray(img);  
end  
subplot(2,3,1);
imshow(img,[]);
title('原始图像');
J=fft2(img);
J=fftshift(J); 
J=abs(J);
subplot(2,3,2);
imshow(log(1+J),[]);
title('原始增强');  

J1=imnoise(img, 'salt & pepper', 0.02); 
subplot(2,3,3);
imshow(J1,[]);
title('椒盐');
J1=fft2(J1);
J1=fftshift(J1);
J1=abs(J1);
subplot(2,3,4);
imshow(log(1+J1),[]);
title('椒盐增强');  

J2=imnoise(img, 'gaussian', 0.02); 
subplot(2,3,5);
imshow(J2,[]);
title('高斯');
J2=fft2(J2);
J2=fftshift(J2); 
J2=abs(J2); 
subplot(2,3,6);
imshow(log(1+J2),[]);
title('高斯增强'); 


% --------------------------------------------------------------------
function enhance_Callback(hObject, eventdata, handles)
% hObject    handle to enhance (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function gray_Callback(hObject, eventdata, handles)
global img;
subplot(2,2,1);
imshow(img);title('原始图像');
subplot(2,2,2);
imhist(img);title('灰度直方图');

imgnew=imadjust(img,[0.1,0.9],[0.1,0.9])
subplot(2,2,3);
imshow(imgnew);title('变换后的灰度图像');
subplot(2,2,4);
imhist(imgnew);title('变换后的灰度直方图');


% --------------------------------------------------------------------
function equalization_Callback(hObject, eventdata, handles)
% hObject    handle to equalization (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function color_Callback(hObject, eventdata, handles)
global img;
%m,n行列，channel通道为1是灰色
[m,n,channel]=size(img);
if channel~=3
    msgbox('not a color pic','title','modal');
    return;
end;
R=img(:,:,1);
G=img(:,:,2);
B=img(:,:,3);
subplot(4,3,1);imshow(img);title('原始图像');

subplot(4,3,4);imshow(R);title('原始图像-R');
subplot(4,3,5);imhist(R);title('灰度直方图-R');
R1=histeq(R,64);subplot(4,3,6);imhist(R1);title('均衡化后灰度直方图-R');

subplot(4,3,7);imshow(G);title('原始图像-G');
subplot(4,3,8);imhist(G);title('灰度直方图-G')
G1=histeq(G,64);subplot(4,3,9);imhist(G1);title('均衡化后灰度直方图-G');

subplot(4,3,10);imshow(B);title('原始图像-B');
subplot(4,3,11);imhist(B);title('灰度直方图-B')
B1=histeq(B,64);subplot(4,3,12);imhist(B1);title('均衡化后灰度值方图-B');

imgnew=cat(3,R1,G1,B1);
subplot(4,3,2);imshow(imgnew);title('最终图像');


% --------------------------------------------------------------------
function matlab_Callback(hObject, eventdata, handles)
% hObject    handle to matlab (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --------------------------------------------------------------------
function gary_Callback(hObject, eventdata, handles)
global img;
subplot(2,2,1);
imshow(img);title('原始图像');
subplot(2,2,2);
imhist(img);title('灰度直方图');

imgnew=histeq(img,64);
subplot(2,2,3);
imshow(imgnew);title('均衡化后灰度变换');
subplot(2,2,4);
imhist(imgnew);title('均衡化后灰度直方图');


% --------------------------------------------------------------------
function Domain_average_Callback(hObject, eventdata, handles)
global img;
im_noise = imnoise(img,'salt & pepper',0.02)
[m,n,channel]=size(img);
H1=ones(3,3)/9; %or: H1=fspecial('average',3);
H2=ones(5,5)/25;
H3=ones(9,9)/81;
if channel==1
    M1=filter2(H1,im_noise);
    M2=filter2(H2,im_noise);
    M3=filter2(H3,im_noise);
else channel== 3
    M1=imfilter(im_noise,H1);
    M2=imfilter(im_noise,H2);
    M3=imfilter(im_noise,H3);
end;
subplot(2,3,2);imshow(im_noise);title('椒盐噪声');
subplot(2,3,4);imshow(uint8(M1));title('3*3');
subplot(2,3,5);imshow(uint8(M2));title('5*5');
subplot(2,3,6);imshow(uint8(M1));title('9*9');



% --------------------------------------------------------------------
function median_filtering_Callback(hObject, eventdata, handles)
global img;
J1=imnoise(img, 'salt & pepper', 0.02);
J2=imnoise(img, 'gaussian', 0.02); 
J3=imnoise(img, 'speckle', 0.02);
[m,n,channel]=size(img);
if channel == 1
    img1=medfilt2(J1,[5,5]);
    img2=medfilt2(J2,[5,5]);
    img3=medfilt2(J3,[5,5]);
else channel == 3
    R=J1(:,:,1);
    G=J1(:,:,2);
    B=J1(:,:,3);
    M1=medfilt2(R,[5,5]);
    M2=medfilt2(G,[5,5]);
    M3=medfilt2(B,[5,5]);
    img1=cat(3,M1,M2,M3);
    R=J2(:,:,1);
    G=J2(:,:,2);
    B=J2(:,:,3);
    M1=medfilt2(R,[5,5]);
    M2=medfilt2(G,[5,5]);
    M3=medfilt2(B,[5,5]);
    img2=cat(3,M1,M2,M3);   
    R=J3(:,:,1);
    G=J3(:,:,2);
    B=J3(:,:,3);
    M1=medfilt2(R,[5,5]);
    M2=medfilt2(G,[5,5]);
    M3=medfilt2(B,[5,5]);
    img3=cat(3,M1,M2,M3);
end;
subplot(2,4,1);
imshow(img);
title('原图像');
subplot(2,4,2);
imshow(J1);
title('椒盐噪声');
subplot(2,4,3);
imshow(J2);
title('高斯噪声');
subplot(2,4,4);
imshow(J3);
title('乘性噪声');
subplot(2,4,5);
imshow(img1);
title('中值滤波-椒盐');
subplot(2,4,6);
imshow(img2);
title('中值滤波-高斯');
subplot(2,4,7);
imshow(img3);
title('中值滤波-乘性');


% --------------------------------------------------------------------
function Domain_average_median_filtering_Callback(hObject, eventdata, handles)
global img;
J1=imnoise(img, 'salt & pepper', 0.02);
[m,n,channel]=size(img);
H2=ones(5,5)/25;
if channel==1
    img_f=filter2(H2,J1);
    img_m=medfilt2(J1,[5,5]);
else channel== 3
    img_f=imfilter(J1,H2);
    R=J1(:,:,1);
    G=J1(:,:,2);
    B=J1(:,:,3);
    M1=medfilt2(R,[5,5]);
    M2=medfilt2(G,[5,5]);
    M3=medfilt2(B,[5,5]);
    img_m=cat(3,M1,M2,M3);
end;
subplot(2,2,1),imshow(img);title('原图像')
subplot(2,2,2);imshow(J1);title('椒盐噪声');
subplot(2,2,3);imshow(uint8(img_f));title('领域平均');
subplot(2,2,4);imshow(uint8(img_m));title('中值滤波');


% --------------------------------------------------------------------
function Specific_numerical_testing_Callback(hObject, eventdata, handles)
img=[1 2 2 2 3;
     1 15 1 2 2;
     2 1 2 0 3;
     0 2 2 3 1;
     3 2 0 2 2];
H=ones(3,3)/9;
img_f = filter2(img,H,'same');
img_m=medfilt2(img);


% --------------------------------------------------------------------
function sharpening_Callback(hObject, eventdata, handles)
% hObject    handle to sharpening (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function Laplace_operator_Callback(hObject, eventdata, handles)
global img;
lap = [0 1 0;1 -4 -1;0 1 0]; % 拉普拉斯算子
[m,n,channel]=size(img);
if channel==1
    img_sharp = filter2(lap,img);
else channel== 3
    img_sharp=imfilter(img,lap);
end;
imgnew = img-uint8(img_sharp);
subplot(1,3,1);imshow(img);title('原始图像');
subplot(1,3,2);imshow(uint8(img_sharp));title('拉普拉斯处理后');
subplot(1,3,3);imshow(imgnew);title('增强图像');


function sobel_Callback(hObject, eventdata, handles)
global img;
dx=[1 0 -1;2 0 -2;1 0 -1];
dy=[-1 -2 -1;0 0 0;1 2 1];
[m,n,channel]=size(img);
if channel==1
    sobx = filter2(dx,img);
    soby = filter2(dy,img);
else channel == 3
    sobx=imfilter(img,dx);
    soby=imfilter(img,dy);
end;
subplot(1,4,1);imshow(img);title('原始图像');
subplot(1,4,2);imshow(uint8(sobx));title('sobel算子dx');
subplot(1,4,3);imshow(uint8(soby));title('sobel算子dy');
subplot(1,4,4);imshow(uint8(sobx)+uint8(soby));title('sobel算子dx+dy');



% --------------------------------------------------------------------
function prewitte_Callback(hObject, eventdata, handles)
global img;
dx=[1 0 -1;1 0 -1;1 0 -1];
dy=[-1 -1 -1;0 0 0;1 1 1];
[m,n,channel]=size(img);
if channel==1
    prex = filter2(dx,img);
    prey = filter2(dy,img);
else channel == 3
    prex=imfilter(img,dx);
    prey=imfilter(img,dy);
end;
subplot(1,4,1);imshow(img);title('原始图像');
subplot(1,4,2);imshow(uint8(prex));title('prewitte算子dx');
subplot(1,4,3);imshow(uint8(prey));title('prewitte算子dy');
subplot(1,4,4);imshow(uint8(prex)+uint8(prey));title('prewitte算子dx+dy');


% --------------------------------------------------------------------
function gradient_Callback(hObject, eventdata, handles)
global img;
subplot(2,3,1);imshow(img);title('原始图像');
[ix, iy] = gradient(double(img));
gm = sqrt(ix.*ix+iy.*iy);
out1 = gm;
subplot(2,3,2);imshow(uint8(out1));title('0');

out2=img;
j=find(gm>=16);
out2(j)=gm(j);
subplot(2,3,3);imshow(uint8(out2));title('16');

out3=img;
j=find(gm>=64);
out3(j)=gm(j);
subplot(2,3,4);imshow(uint8(out3));title('64');

out4=img;
j=find(gm>=128);
out4(j)=gm(j);
subplot(2,3,5);imshow(uint8(out4));title('128');

out5=img;
j=find(gm>=256);
out5(j)=gm(j);
subplot(2,3,6);imshow(uint8(out5));title('256');



% --------------------------------------------------------------------
function smooth_Callback(hObject, eventdata, handles)
% hObject    handle to smooth (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --------------------------------------------------------------------
function low_pass_Callback(hObject, eventdata, handles)
global img;
subplot(1,3,1);imshow(img);title('原始图像');
img_noise=imnoise(img,'salt & pepper',0.02);
subplot(1,3,2);imshow(img_noise);title('噪声图像');
F=fft2(img_noise);
F=fftshift(F);
[M N]=size(img);
u1=fix(M/2);u2=fix(N/2);
D0=100;
for u=1:M
    for v=1:N
        D=sqrt((u-u1)^2+(v-u2)^2);
        if(D<D0)H=1;
        else H=0;
        end
        result(u,v)=H*F(u,v);
    end
end
result=ifftshift(result);
J1=ifft2(result);
J2=uint8(real(J1));
subplot(1,3,3);imshow(J2);title('低通滤波图像');
    






