# GRAYSCALE MODEL 


# !pip install kaggle

from google.colab import files
files.upload()

!mkdir ~p ~/.kaggle
!cp kaggle.json ~/.kaggle/

!chmod 600 ~/.kaggle/kaggle.json

!kaggle datasets download -d puneet6060/intel-image-classification

from zipfile import ZipFile
file_name="intel-image-classification.zip"

with ZipFile(file_name,'r') as zip:
  zip.extractall()
  print('done')
  
  
import tensorflow as tf

from sklearn.datasets import load_files
import numpy as np

train_dir = './seg_train/seg_train'
test_dir = './seg_test/seg_test'

def load_dataset(path):
  data = load_files(path)
  files = np.array(data['filenames'])
  targets = np.array(data['target'])
  target_labels = np.array(data['target_names'])
  return files,targets,target_labels
    
x_train, y_train,target_labels = load_dataset(train_dir)
x_test, y_test,_ = load_dataset(test_dir)
print('Loading complete!')

print('Training set size : ' , x_train.shape[0])
print('Testing set size : ', x_test.shape[0])

no_of_classes = len(np.unique(y_train))
no_of_classes


print(y_train[0:10])
# target labels are numbers corresponding to class label. We need to change them to a vector of 81 elements.

from keras.utils import np_utils
y_train = np_utils.to_categorical(y_train,no_of_classes)
y_test = np_utils.to_categorical(y_test,no_of_classes)
y_train[0] # Note that only one element has value 1(corresponding to its label) and others are 0.

len(x_train)  #14008
len(x_test)  # 3000

x_train[0]
# training data is just file names of images. We need to convert them into pixel matrix.

# We just have the file names in the x set. Let's load the images and convert them into array.
from keras.preprocessing.image import array_to_img, img_to_array, load_img

def convert_image_to_array(files):
    images_as_array=[]
    for file in files:
        # Convert to Numpy Array
        images_as_array.append(img_to_array( load_img(file,target_size=(100,100),color_mode="grayscale") ))
    return images_as_array

x_train = np.array(convert_image_to_array(x_train))
print('Training set shape : ',x_train.shape)

x_test = np.array(convert_image_to_array(x_test))
print('Test set shape : ',x_test.shape)

print('1st training image shape ',x_train[0].shape)

print('1st training image as array',x_train[0]) # don't worry if you see only 255s..
# there are elements will other values too :p


# time to re-scale so that all the pixel values lie within 0 to 1
x_train = np.true_divide(x_train, 255)
x_test = np.true_divide(x_test, 255)
x_train[0]


#Simple CNN from scratch - we are using 3 Conv layers followed by maxpooling layers.
# At the end we add dropout, flatten and some fully connected layers(Dense).

from keras.models import Sequential
from keras.layers import Conv2D,MaxPooling2D
from keras.layers import Activation, Dense, Flatten, Dropout
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ModelCheckpoint
from keras import backend as K

# del(model)

model = Sequential()
model.add(Conv2D(filters = 128, kernel_size = 2,activation= 'relu', input_shape=(100,100,1),padding='same'))
model.add(MaxPooling2D(pool_size=2))

model.add(Conv2D(filters = 64,kernel_size = 2,activation= 'relu',padding='same'))
model.add(MaxPooling2D(pool_size=2))


model.add(Dropout(0.3))
model.add(Flatten())
model.add(Dense(32,kernel_initializer='glorot_uniform',activation = 'relu'))
model.add(Dropout(0.4))
model.add(Dense(6,activation = 'softmax'))
model.summary()


model.compile(loss='categorical_crossentropy',
              optimizer='adam',
              metrics=['accuracy'])

print('Compiled!')

batch_size = 32

checkpointer = ModelCheckpoint(filepath = 'cnn_from_intel_class.hdf5', verbose = 1, save_best_only = True)


history = model.fit(x_train,y_train,
        batch_size = 32,
        epochs=20,
        validation_data=(x_test, y_test),
        callbacks = [checkpointer],
        verbose=2, shuffle=True)



# load the weights that yielded the best validation accuracy
model.load_weights('cnn_from_intel_class_grayscale.hdf5')

# saving the model with 76.60% accuracy
model.save('cnn_intel_class_grayscale.model')

# loading the saved model
from keras.models import load_model
model1 = load_model('kadak_model.model')

# evaluate and print test accuracy
score = model.evaluate(x_test, y_test, verbose=0)
print('\n', 'Test accuracy:', score[1])


# Let's visualize test prediction.

y_pred = model.predict(x_test)

import pickle

pickle_out = open("x_train_intel.pickle","wb")
pickle.dump(x_train, pickle_out)
pickle_out.close()


pickle_out = open("y_train_intel.pickle","wb")
pickle.dump(y_train, pickle_out)
pickle_out.close()


pickle_out = open("x_test_intel.pickle","wb")
pickle.dump(x_test, pickle_out)
pickle_out.close()

pickle_out = open("y_test_intel.pickle","wb")
pickle.dump(y_test, pickle_out)
pickle_out.close()


pickle_in = open("y_test_intel.pickle","rb")
y_test = pickle.load(pickle_in)




# *************************   RGB MODEL   *************************** 




# RGB Model

import tensorflow as tf

from sklearn.datasets import load_files
import numpy as np

train_dir = './seg_train/seg_train'
test_dir = './seg_test/seg_test'

def load_dataset(path):
  data = load_files(path)
  files = np.array(data['filenames'])
  targets = np.array(data['target'])
  target_labels = np.array(data['target_names'])
  return files,targets,target_labels
    
x_train1, y_train1,target_labels1 = load_dataset(train_dir)
x_test1, y_test1,_ = load_dataset(test_dir)
print('Loading complete!')

print('Training set size : ' , x_train1.shape[0])
print('Testing set size : ', x_test1.shape[0])

no_of_classes = len(np.unique(y_train1))
no_of_classes


print(y_train1[0:10])
# target labels are numbers corresponding to class label. We need to change them to a vector of 81 elements.

from keras.utils import np_utils
y_train1 = np_utils.to_categorical(y_train1,no_of_classes)
y_test1 = np_utils.to_categorical(y_test1,no_of_classes)
y_train1[0] # Note that only one element has value 1(corresponding to its label) and others are 0.

len(x_train1)  #14008
len(x_test1)  # 3000

x_train1[0]
# training data is just file names of images. We need to convert them into pixel matrix.

# We just have the file names in the x set. Let's load the images and convert them into array.
from keras.preprocessing.image import array_to_img, img_to_array, load_img

def convert_image_to_array(files):
    images_as_array=[]
    for file in files:
        # Convert to Numpy Array
        images_as_array.append(img_to_array( load_img(file,target_size=(100,100),color_mode="rgb") ))
    return images_as_array

x_train1 = np.array(convert_image_to_array(x_train1))
print('Training set shape : ',x_train1.shape)

x_test1 = np.array(convert_image_to_array(x_test1))
print('Test set shape : ',x_test1.shape)

print('1st training image shape ',x_train1[0].shape)

print('1st training image as array',x_train1[0]) # don't worry if you see only 255s..
# there are elements will other values too :p


# time to re-scale so that all the pixel values lie within 0 to 1
x_train1 = np.true_divide(x_train1, 255)
x_test1 = np.true_divide(x_test1, 255)
x_train1[0]


#Simple CNN from scratch - we are using 3 Conv layers followed by maxpooling layers.
# At the end we add dropout, flatten and some fully connected layers(Dense).

from keras.models import Sequential
from keras.layers import Conv2D,MaxPooling2D
from keras.layers import Activation, Dense, Flatten, Dropout
from keras.preprocessing.image import ImageDataGenerator
from keras.callbacks import ModelCheckpoint
from keras import backend as K

# del(model)

model1 = Sequential()
model1.add(Conv2D(filters = 128, kernel_size = 2,activation= 'relu', input_shape=(100,100,3),padding='same'))
model1.add(MaxPooling2D(pool_size=2))

model1.add(Conv2D(filters = 64,kernel_size = 2,activation= 'relu',padding='same'))
model1.add(MaxPooling2D(pool_size=2))


model1.add(Dropout(0.3))
model1.add(Flatten())
model1.add(Dense(32,kernel_initializer='glorot_uniform',activation = 'relu'))
model1.add(Dropout(0.4))
model1.add(Dense(6,activation = 'softmax'))
model1.summary()


model1.compile(loss='categorical_crossentropy',
              optimizer='adam',
              metrics=['accuracy'])

print('Compiled!')

batch_size = 32

checkpointer = ModelCheckpoint(filepath = 'cnn_from_intel_class_rgb.hdf5', verbose = 1, save_best_only = True)


history = model1.fit(x_train1,y_train1,
        batch_size = 32,
        epochs=20,
        validation_data=(x_test1, y_test1),
        callbacks = [checkpointer],
        verbose=2, shuffle=True)



# load the weights that yielded the best validation accuracy
# model1.load_weights('cnn_from_intel_class_rgb.hdf5')

# saving the model with 78.9% accuracy
model1.save('cnn_intel_class_rgb.model')

# loading the saved model
from keras.models import load_model
model1 = load_model('kadak_model.model')

# evaluate and print test accuracy
score1 = model1.evaluate(x_test1, y_test1, verbose=0)
print('\n', 'Test accuracy:', score1[1])


# Let's visualize test prediction.

y_pred1 = model1.predict(x_test1)



# **********************

# del(model2)

model2 = Sequential()
model2.add(Conv2D(filters = 128, kernel_size = 2,activation='relu',input_shape=(100, 100, 3),padding='same'))
model2.add(MaxPooling2D(pool_size=2))

model2.add(Conv2D(filters = 64,kernel_size = 2,activation= 'relu',padding='same'))
model2.add(MaxPooling2D(pool_size=2))

model2.add(Conv2D(filters =32,kernel_size = 2,activation= 'relu',padding='same'))
model2.add(MaxPooling2D(pool_size=2))

model2.add(Conv2D(filters = 16,kernel_size = 2,activation= 'relu',padding='same'))
model2.add(MaxPooling2D(pool_size=2))

model2.add(Dropout(0.3))
model2.add(Flatten())

model2.add(Dense(30,activation = 'relu'))

model2.add(Dropout(0.4))
model2.add(Dense(6,activation = 'softmax'))

model2.summary()


model2.compile(loss='categorical_crossentropy',
              optimizer='adam',
              metrics=['accuracy'])


checkpointer1 = ModelCheckpoint(filepath = 'cnn_from_intel_class_rgb1.hdf5', verbose = 1, save_best_only = True)


history1 = model2.fit(x_train1,y_train1,
        batch_size = 32,
        epochs=20,
        validation_data=(x_test1, y_test1),
        callbacks = [checkpointer1],
        verbose=2, shuffle=True)

from keras.models import load_model
model2.load_weights('cnn_from_intel_class_rgb1.hdf5')

# evaluate and print test accuracy
score1 = model2.evaluate(x_test1, y_test1, verbose=0)
print('\n', 'Test accuracy:', score1[1])

model2.save('cnn_intel_class_rgb1.model')

# model with 84.66% accuracy

# **********************
model3=load_model('cnn_intel_class_rgb1.model')

model3.load_weights('cnn_from_intel_class_rgb1.hdf5')


import numpy as np
from keras.preprocessing import image

test_image = image.load_img('10006.jpg', target_size = (100,100))
test_image = image.img_to_array(test_image)

test_image = np.true_divide(test_image, 255)

test_image = np.expand_dims(test_image, axis = 0)
result = model3.predict(test_image)

np.argmax(result)

# {'buildings' -> 0, 'forest' -> 1, 'glacier' -> 2, 'mountain' -> 3, 'sea' -> 4, 'street' -> 5 }
