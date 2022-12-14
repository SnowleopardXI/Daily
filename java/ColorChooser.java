import java.awt.*;
import javax.swing.*;
public class ColorChooser extends JFrame {
    private static final long serialVersionUID = 1L;
    private static final int WIDTH = 300;
    private static final int HEIGHT = 200;
    private static final String TITLE = "Color Chooser";
    private static final String TEXT_COLOR_BUTTON_TEXT = "文本颜色";
    private static final String BACKGROUND_COLOR_BUTTON_TEXT = "背景颜色";
    private static final String CLOSE_BUTTON_TEXT = "关闭窗体";
    private static final String TEXT = "Text Information";
    private static final String TEXT_COLOR_CHOOSER_TITLE = "Text Color Chooser";
    private static final String BACKGROUND_COLOR_CHOOSER_TITLE = "Background Color Chooser";
    private static final int background_width = 200;
    private static final int background_height = 80;
    public static void main(String[] args) {
        ColorChooser cc = new ColorChooser();
        cc.show();
    }
    private JButton textColorButton;
    private JButton backgroundColorButton;
    private JButton closeButton;
    private JLabel textLabel;
    public ColorChooser() {
        super(TITLE);
        setSize(WIDTH, HEIGHT);
        setLayout(new FlowLayout());
        textColorButton = new JButton(TEXT_COLOR_BUTTON_TEXT);
        textColorButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                textColorButtonActionPerformed(e);
            }
        });
        add(textColorButton);
        backgroundColorButton = new JButton(BACKGROUND_COLOR_BUTTON_TEXT);
        backgroundColorButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                backgroundColorButtonActionPerformed(e);
            }
        });
        add(backgroundColorButton);
        closeButton = new JButton(CLOSE_BUTTON_TEXT);
        closeButton.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent e) {
                closeButtonActionPerformed(e);
            }
        });
        add(closeButton);
        textLabel = new JLabel(TEXT);
        textLabel.setOpaque(true);
        textLabel.setBackground(Color.WHITE);
        textLabel.setPreferredSize(new Dimension(background_width, background_height));
        add(textLabel);
        new JColorChooser();
        new JColorChooser();
    }
    private void textColorButtonActionPerformed(java.awt.event.ActionEvent e) {
        Color color = JColorChooser.showDialog(this, TEXT_COLOR_CHOOSER_TITLE, Color.BLACK);
        textLabel.setForeground(color);
    }
    private void backgroundColorButtonActionPerformed(java.awt.event.ActionEvent e) {
        Color color = JColorChooser.showDialog(this, BACKGROUND_COLOR_CHOOSER_TITLE, Color.WHITE);
        textLabel.setBackground(color);
    }
    private void closeButtonActionPerformed(java.awt.event.ActionEvent e) {
        System.exit(0);
    }
    
}