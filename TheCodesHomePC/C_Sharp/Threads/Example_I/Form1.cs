using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Threads
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            this.Load += Form1_Load;

            buttonRed.Click += buttonRed_Click;
            buttonGreen.Click += buttonGreen_Click;
            buttonBlue.Click += buttonBlue_Click;
        }

        Random rnd;
        Thread threadForRed;
        Thread threadForGreen;
        Thread threadForBlue;

        private void buttonRed_Click(object sender, EventArgs e)
        {
            // methodRed();
            threadForRed = new Thread(methodRed);
            threadForRed.Start();
        }

        private void buttonGreen_Click(object sender, EventArgs e)
        {
            // methodGreen();
            threadForGreen = new Thread(methodGreen);
            threadForGreen.Start();
        }

        private void buttonBlue_Click(object sender, EventArgs e)
        {
            // methodBlue();
            threadForBlue = new Thread(methodBlue);
            threadForBlue.Start();
        }

        private void Form1_Load(object sender, EventArgs events)
        {
            rnd = new Random();
        }

        public void methodRed()
        {
            for (int i = 0; i < 100; i++)
            {
                this.CreateGraphics().DrawRectangle(
                                                    new Pen(Brushes.Red, 4),
                                                    new Rectangle(
                                                                rnd.Next(0, this.Width), 
                                                                rnd.Next(0, this.Height), 
                                                                30, 30 )
                                                    );
            }

            Thread.Sleep(100);
        }

        public void methodGreen()
        {
            for (int i = 0; i < 100; i++)
            {
                this.CreateGraphics().DrawRectangle(
                                                    new Pen(Brushes.Green, 4),
                                                    new Rectangle(
                                                                rnd.Next(0, this.Width),
                                                                rnd.Next(0, this.Height),
                                                                30, 30)
                                                    );
            }

            Thread.Sleep(125);
        }

        public void methodBlue()
        {
            for (int i = 0; i < 100; i++)
            {
                this.CreateGraphics().DrawRectangle(
                                                    new Pen(Brushes.Blue, 4),
                                                    new Rectangle(
                                                                rnd.Next(0, this.Width),
                                                                rnd.Next(0, this.Height),
                                                                30, 30)
                                                    );
            }
            
            Thread.Sleep(150);
        }
    }
}
