//
//  YHJTagList.h
//  RefreshDetail
//
//  Created by 余洪江 on 16/2/29.
//  Copyright © 2016年 m. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MRJTagListDelegate, MRJTagViewDelegate;

@interface MRJTagList : UIScrollView {
    UIView      *view;
    NSArray     *textArray;
    CGSize      sizeFit;
    UIColor     *lblBackgroundColor;
}

@property (nonatomic) BOOL viewOnly;
@property (nonatomic) BOOL showTagMenu;
@property (nonatomic, strong) UIView *view;
@property (nonatomic, strong) NSArray *textArray;
@property (nonatomic, weak) id<MRJTagListDelegate> tagDelegate;
@property (nonatomic, strong) UIColor *highlightedBackgroundColor;
@property (nonatomic) BOOL automaticResize;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, assign) CGFloat labelMargin;
@property (nonatomic, assign) CGFloat bottomMargin;
@property (nonatomic, assign) CGFloat horizontalPadding;
@property (nonatomic, assign) CGFloat verticalPadding;
@property (nonatomic, assign) CGFloat minimumWidth;
@property (nonatomic, assign) CGFloat cornerRadius;
@property (nonatomic, strong) UIColor *borderColor;
@property (nonatomic, assign) CGFloat borderWidth;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, strong) UIColor *textShadowColor;
@property (nonatomic, assign) CGSize textShadowOffset;
@property (nonatomic, strong) UIColor *selectBackColor;

/**
 *  是否允许点击, 默认YES
 */
@property (nonatomic, assign) BOOL isTouch;

/**
 *  是否选择多选, 默认NO
 */
@property (nonatomic, assign) BOOL isManySelect;

- (void)setTagBackgroundColor:(UIColor *)color;
- (void)setTagHighlightColor:(UIColor *)color;
- (void)setTags:(NSArray *)array;
- (void)display;
- (CGSize)fittedSize;
- (void)scrollToBottomAnimated:(BOOL)animated;

@end

@interface MRJTagView : UIView

@property (nonatomic, strong) UIButton *button;
@property (nonatomic, strong) UILabel *label;
@property (nonatomic, assign) BOOL isSelected;
@property (nonatomic, weak) id<MRJTagViewDelegate> delegate;

- (void)updateWithString:(NSString *)text
                    font:(UIFont *)font
      constrainedToWidth:(CGFloat)maxWidth
                 padding:(CGSize)padding
            minimumWidth:(CGFloat)minimumWidth;
- (void)setLabelText:(NSString *)text;
- (void)setCornerRadius:(CGFloat)cornerRadius;
- (void)setBorderColor:(CGColorRef)borderColor;
- (void)setBorderWidth:(CGFloat)borderWidth;
- (void)setTextColor:(UIColor *)textColor;
- (void)setTextShadowColor:(UIColor*)textShadowColor;
- (void)setTextShadowOffset:(CGSize)textShadowOffset;

@end


@protocol MRJTagListDelegate <NSObject>

@optional

/**
 *  单个标签
 *
 *  @param tagName  标签值
 *  @param tagIndex 标签下标
 */
- (void)selectedTag:(NSString *)tagName tagIndex:(NSInteger)tagIndex;
- (void)selectedTag:(NSString *)tagName;
- (void)tagListTagsChanged:(MRJTagList *)tagList;

/**
 *  多标签的代理方法
 *
 *  @param tagNames  多标签的名称
 *  @param tagIndexs 多标签的下标值
 */
- (void)selectedTags:(NSArray *)tagNames tagIndex:(NSArray *)tagIndexs;

@end

@protocol MRJTagViewDelegate <NSObject>

@required

- (void)tagViewWantsToBeDeleted:(MRJTagView *)tagView;

@end
