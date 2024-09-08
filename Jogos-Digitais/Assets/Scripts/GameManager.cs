using UnityEngine.UI;
using UnityEngine;

public class GameManager : MonoBehaviour
{

    public Inimigo[] inimigos;
    public Player player;
    public Transform halter;
    public int multiplicadorInimigo { get; private set; } = 1;
    public int score { get; private set; }
    public int vidas { get; private set; }
    private void Start()
    {
        NewGame();
    }

    private void Update()
    {
        if (this.vidas <= 0 && Input.anyKeyDown)
        {
            NewGame();
        }
    }

    private void NewGame()
    {
        SetScore(0);
        SetVidas(3);
        NovoRound();
    }

    private void NovoRound()
    {
        foreach (Transform halteres in this.halter)
        {
            halteres.gameObject.SetActive(true);
        }
        ResetState();
    }

    private void ResetState()
    {
        ResetaMultiplicadorInimigo();
        for (int i = 0; i < this.inimigos.Length; i++)
        {
            this.inimigos[i].ResetState();
        }

        this.player.ResetState();
    }
    private void GameOver()
    {

        for (int i = 0; i < this.inimigos.Length; i++)
        {
            this.inimigos[i].gameObject.SetActive(false);
        }

        this.player.gameObject.SetActive(false);
    }
    private void SetScore(int score)
    {
        this.score = score;
    }

    private void SetVidas(int vidas)
    {
        this.vidas = vidas;
    }

    public void InimigoDerrotado(Inimigo inimigo)
    {
        int pontos = inimigo.pontos  * multiplicadorInimigo;
        SetScore(this.score + (inimigo.pontos * this.multiplicadorInimigo));
        this.multiplicadorInimigo++;
    }

    public void PlayerDerrotado()
    {
        this.player.gameObject.SetActive(false);

        SetVidas(this.vidas - 1);

        if (this.vidas > 0)
        {
            Invoke(nameof(ResetState), 3.0f);
        }
        else
        {
            GameOver();
        }
    }

    public void HalterConsumido(Halter halter)
    {
        halter.gameObject.SetActive(false);

        SetScore(this.score + halter.pontos);

        if (!AindaTemHalter())
        {
            this.player.gameObject.SetActive(false);
            Invoke(nameof(NovoRound), 3.0f);
        }
    }

    public void WheyConsumido(Whey whey)
    {
        for (int i = 0; i < this.inimigos.Length; i++)
        {
            this.inimigos[i].assustado.Enable(whey.duracao);
        }

        HalterConsumido(whey);
        CancelInvoke();
        Invoke(nameof(ResetaMultiplicadorInimigo), whey.duracao);
    }

    private bool AindaTemHalter()
    {
        foreach (Transform halteres in this.halter)
        {
            if (halteres.gameObject.activeSelf)
            {
                return true;
            }
        }
        return false;
    }

    private void ResetaMultiplicadorInimigo()
    {
        this.multiplicadorInimigo = 1;
    }
}
