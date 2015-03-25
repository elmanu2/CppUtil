#ifndef Point2D_H
#define Point2D_H

#ifdef CPPUTILBUILDDLL
#define CPPUTILEXPORT  __declspec( dllexport ) 
#else
#define CPPUTILEXPORT  __declspec( dllimport ) 
#endif

#include <vector>

/**
 * @brief Point 2D x/y
 */
class CPPUTILEXPORT Point2D
{
public :
    /**
     * Constructeur par defaut
     */
    Point2D();

    /**
     * Destructeur
     */
    virtual ~Point2D();

    /**
     * Constructeur
     * @param x_ coordonee x
     * @param y_ y coordonee y
     */
    Point2D(double x_, double y_);

    /**
     * Constructeur par copie
     * @param source_
     */
    Point2D(const Point2D&source_);

    /**
     * Constructeur from vector
     * @param xy_
     */
    Point2D(std::vector<double> xy_);

    /**
     * redefinition de l operateur d assignement
     * @param source_
     * @return
     */
    Point2D operator= (const Point2D& source_);

    /**
     * redefinition de l operateur d egalite
     * @param source_
     * @return
     */
    bool operator== (const Point2D& source_);

    /**
     * redefinition de l operateur de soustraction
     * @param pt2_
     * @return
     */
    Point2D operator- (const Point2D& pt2_) const;

    /**
     * redefinition de l operateur de soustraction
     * @param value
     * @return
     */
    Point2D operator- (const double& value_) const;

    /**
     * redefinition de l operateur d addition
     * @param pt2_
     * @return
     */
    Point2D operator+ (const Point2D& pt2_) const;

    /**
     * redefinition de l operateur d addition
     * @param value
     * @return
     */
    Point2D operator+ (const double& value_) const;

    /**
     * redefinition de l operateur de multiplication
     * @param pt2_
     * @return
     */
    Point2D operator* (const Point2D& pt2_) const;

    /**
     * redefinition de l operateur de multiplication
     * @param value_
     * @return
     */
    Point2D operator* (const double& value_) const;

    /**
     * redefinition de l operateur de division
     * @param pt2_
     * @return
     */
    Point2D operator/ (const Point2D& pt2_) const;

    /**
     * redefinition de l operateur de division
     * @param pt2_
     * @return
     */
    Point2D operator/ (const double& value_) const;

    /**
     * inverser les coordonnees
     * @param pt2_
     * @return
     */
    void inverserXY();

    static void test();

public :

    double _x; //! coordonnee x
    double _y; //! coordonnee y
};


#endif // PoinD2D_H
