img = imread('image.jpg');
T = [0.3,0.1,0;0.5,1.9,1;0,0,1];
T = T';
tform = maketform('affine',T);
imgout = imtransform(img,tform);
figure
imshow(imgout);
imwrite(imgout,'P3.jpg');

%%The inverse version
T = T^(-1);
in_tform = maketform('affine',T);
in_imgout = imtransform(imgout,in_tform);
x_pos = (size(in_imgout,2)- size(img,2))/2;
y_pos = (size(in_imgout,1)- size(img,1))/2;
in_imgout = imcrop(in_imgout,[x_pos y_pos 1920 1080]);

figure
imshow(in_imgout);
imwrite(in_imgout,'P3_inverse.jpg');