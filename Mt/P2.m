%% rescaling and rotating image

img = imread('image.jpg');

tmp =  imresize(img,[2.4*size(img,1) size(img,2)/1.4],'bicubic');

tmp = imrotate(tmp,-33.5,'bicubic');

figure
imshow(tmp);
imwrite(tmp,'P2.jpg');

%% inverse transformation 
in_tmp = imrotate(tmp,33.5,'bicubic');

in_img = imresize(in_tmp,[size(in_tmp,1)/2.4 1.4*size(in_tmp,2)],'bicubic');
x_pos = (size(in_img,2)- size(img,2))/2;
y_pos = (size(in_img,1)- size(img,1))/2;
in_img = imcrop(in_img,[x_pos y_pos 1920 1080]);

figure
imshow(in_img);
imwrite(in_img,'P2_inverse.jpg');
