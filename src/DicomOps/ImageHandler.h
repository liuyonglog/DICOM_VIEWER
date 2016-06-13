#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H


#include <vector>
#include <memory>
#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QImage>

#include "ImageContainer.h"
#include "ImageIO.h"
#include "ImageFilter.h"


class ImageHandler
{
public:
    ImageHandler();
    virtual ~ImageHandler();

    bool AddImage(QString filename);
    bool AddImageSeries(QString folderPath);
    bool RemoveImage();

    void SetActiveIndex(unsigned int index);
    int GetActiveIndex();
    std::shared_ptr<ImageContainer> GetImageObj();
    int GetNumberOfOpenedImages();

    void DisplayImage(short wc, short ww, int slice, QImage* image);
    void UpdateImage(short wc, short ww, int slice, QImage* image);

    void Paint(QPainter* painter, QPaintEvent* event, int elapsed, QImage* image, const QRect& rect);

private:
    void ITKImageToQImage(ShortImageType::Pointer& itk_image, QImage* qt_image);

private:
    std::vector<std::shared_ptr<ImageContainer>> m_vecImages;
    std::shared_ptr<ImageContainer> m_pCurrentImage;
    int m_iActiveIndex;

};


#endif // IMAGEHANDLER_H
