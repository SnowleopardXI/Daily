import javax.swing.*;
import javax.sound.midi.*;
//file chooser
import java.io.*;
public class MidiPlayer extends JFrame {
    private static final long serialVersionUID = 1L;
    private static final int WIDTH = 300;
    private static final int HEIGHT = 200;
    private static final String TITLE = "Midi Player";
    private static final String FILE_CHOOSER_TITLE = "Select a MIDI file";
    private static final String PLAY_BUTTON_TEXT = "Play";
    private static final String STOP_BUTTON_TEXT = "Stop";
    private static final String PAUSE_BUTTON_TEXT = "Pause";
    private static final String RESUME_BUTTON_TEXT = "Resume";
    private static final String ABOUT_BUTTON_TEXT = "About";
    private static final String ABOUT_TEXT = "Midi Player v1.0";
    @SuppressWarnings("deprecation")
    public static void main(String[] args) {
        MidiPlayer mp = new MidiPlayer();
        mp.show();
    }
    //Menu
    private JMenuBar menuBar;
    private JMenu fileMenu;
    private JMenuItem openMenuItem;
    private JMenuItem exitMenuItem;
    //Buttons
    private JButton playButton;
    private JButton stopButton;
    private JButton pauseButton;
    private JButton resumeButton;
    private JButton aboutButton;
    //File chooser
    private JFileChooser fileChooser;
    //Midi player
    private Sequencer sequencer;
    private Sequence sequence;
    private File file;
    public MidiPlayer() {
        super(TITLE);
        setSize(WIDTH, HEIGHT);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        //Menu
        menuBar = new JMenuBar();
        fileMenu = new JMenu("File");
        openMenuItem = new JMenuItem("Open");
        exitMenuItem = new JMenuItem("Exit");
        fileMenu.add(openMenuItem);
        fileMenu.add(exitMenuItem);
        menuBar.add(fileMenu);
        setJMenuBar(menuBar);
        //Buttons
        playButton = new JButton(PLAY_BUTTON_TEXT);
        stopButton = new JButton(STOP_BUTTON_TEXT);
        pauseButton = new JButton(PAUSE_BUTTON_TEXT);
        resumeButton = new JButton(RESUME_BUTTON_TEXT);
        aboutButton = new JButton(ABOUT_BUTTON_TEXT);
        JPanel buttonPanel = new JPanel();
        buttonPanel.add(playButton);
        buttonPanel.add(stopButton);
        buttonPanel.add(pauseButton);
        buttonPanel.add(resumeButton);
        buttonPanel.add(aboutButton);
        getContentPane().add(buttonPanel);
        //File chooser
        fileChooser = new JFileChooser();
        fileChooser.setDialogTitle(FILE_CHOOSER_TITLE);
        //Midi player
        try {
            sequencer = MidiSystem.getSequencer();
            sequencer.open();
        } catch (MidiUnavailableException e) {
            e.printStackTrace();
        }
        //Listeners
        openMenuItem.addActionListener(e -> {
            int returnVal = fileChooser.showOpenDialog(MidiPlayer.this);
            if (returnVal == JFileChooser.APPROVE_OPTION) {
                file = fileChooser.getSelectedFile();
                try {
                    sequence = MidiSystem.getSequence(file);
                    sequencer.setSequence(sequence);
                } catch (InvalidMidiDataException | IOException e1) {
                    e1.printStackTrace();
                }
            }
        });
        exitMenuItem.addActionListener(e -> System.exit(0));
        playButton.addActionListener(e -> sequencer.start());
        stopButton.addActionListener(e -> sequencer.stop());
        pauseButton.addActionListener(e -> sequencer.stop());
        resumeButton.addActionListener(e -> sequencer.start());
        aboutButton.addActionListener(e -> JOptionPane.showMessageDialog(MidiPlayer.this, ABOUT_TEXT));
    }
}
